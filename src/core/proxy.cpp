#include "proxy.h"
#include <vector>
#include "diag_log.h"

SteamProxy& SteamProxy::Instance() {
    static SteamProxy instance;
    return instance;
}

SteamProxy::~SteamProxy() {
    Shutdown();
}

static bool FileExistsA(const char* path) {
    DWORD attrs = GetFileAttributesA(path);
    return attrs != INVALID_FILE_ATTRIBUTES && !(attrs & FILE_ATTRIBUTE_DIRECTORY);
}

static void DirNameA(const char* path, char* out, size_t outSize) {
    if (!path || !out || outSize == 0) return;
    size_t len = strlen(path);
    for (size_t i = len; i > 0; --i) {
        if (path[i - 1] == '\\' || path[i - 1] == '/') {
            if (i < outSize) {
                memcpy(out, path, i);
                out[i] = '\0';
            } else {
                out[0] = '\0';
            }
            return;
        }
    }
    out[0] = '\0';
}

bool SteamProxy::Init() {
    if (m_bSteamLoaded) return true;

    std::vector<std::string> paths;

    // 1) рядом с нашим модулем и рядом с exe
    char selfPath[MAX_PATH] = {0};
    char exePath[MAX_PATH] = {0};
    HMODULE hSelf = nullptr;
    GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
        (LPCSTR)&SteamProxy::Instance, &hSelf);
    GetModuleFileNameA(hSelf, selfPath, MAX_PATH);
    GetModuleFileNameA(NULL, exePath, MAX_PATH);

    char dir[MAX_PATH] = {0};
    if (selfPath[0]) {
        DirNameA(selfPath, dir, MAX_PATH);
        paths.push_back(std::string(dir) + "steam_api_orig.dll");
    }
    if (exePath[0] && _stricmp(exePath, selfPath) != 0) {
        DirNameA(exePath, dir, MAX_PATH);
        paths.push_back(std::string(dir) + "steam_api_orig.dll");
        paths.push_back(std::string(dir) + "valve\steam_api_orig.dll");
    }

    // 2) стандартная установка Steam
    char progFiles[MAX_PATH] = {0};
    if (GetEnvironmentVariableA("ProgramFiles(x86)", progFiles, MAX_PATH) > 0) {
        paths.push_back(std::string(progFiles) + "\Steam\steam_api.dll");
    }

    for (size_t i = 0; i < paths.size(); ++i) {
        if (!FileExistsA(paths[i].c_str())) continue;
        HMODULE h = LoadLibraryA(paths[i].c_str());
        if (h) {
            // защита от повторной загрузки себя же
            char loaded[MAX_PATH] = {0};
            GetModuleFileNameA(h, loaded, MAX_PATH);
            if (selfPath[0] && _stricmp(loaded, selfPath) == 0) {
                FreeLibrary(h);
                continue;
            }
            m_hSteamAPI = h;
            m_bSteamLoaded = true;
            {
                char mp[MAX_PATH] = {0};
                GetModuleFileNameA(h, mp, MAX_PATH);
                diag::log("proxy: loaded %s", mp);
            }
            return true;
        }
    }

    // Fallback: steam_api_orig.dll не найдена. Если Steam-клиент запущен —
    // подключаемся напрямую к steamclient.dll (ядро Steam): его CreateInterface
    // выдаёт настоящие интерфейсы по версиям (SteamUser023 и т.д.).
    char steamPath[MAX_PATH] = {0};
    DWORD steamPathLen = GetEnvironmentVariableA("SteamPath", steamPath, MAX_PATH);
    HMODULE hSteamClient = nullptr;
    if (steamPathLen > 0) {
        std::string sc = std::string(steamPath) + "\\steamclient.dll";
        if (FileExistsA(sc.c_str())) hSteamClient = LoadLibraryExA(sc.c_str(), NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
    }
    if (!hSteamClient) {
        // типичные пути установки Steam
        if (progFiles[0] == '\0') GetEnvironmentVariableA("ProgramFiles(x86)", progFiles, MAX_PATH);
        if (progFiles[0]) {
            std::string sc = std::string(progFiles) + "\\Steam\\steamclient.dll";
            if (FileExistsA(sc.c_str())) hSteamClient = LoadLibraryExA(sc.c_str(), NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
        }
    }
    if (hSteamClient) {
        // Проксируем на steamclient: его CreateInterface принимает те же строки версий.
        m_hSteamAPI = hSteamClient;
        m_bSteamLoaded = true;
        m_bSteamClientMode = true;
        diag::log("steamclient fallback OK");
        return true;
    }
    diag::log("all proxy paths failed");

    return false;
}

void SteamProxy::Shutdown() {
    if (m_hSteamAPI) {
        FreeLibrary(m_hSteamAPI);
        m_hSteamAPI = nullptr;
    }
    m_bSteamLoaded = false;
}

// steamclient-режим: локальные заглушки жизненного цикла (cdecl, как Valve API)
static bool __cdecl ClientMode_Init() { return true; }
static void __cdecl ClientMode_Void() {}
static void* __cdecl ClientMode_Handle1() { return (void*)1; }
static void* g_pSteamClientObj = nullptr;
// steamclient-режим: прокачка фрейма + диспетчеризация колбэков через Steam_BGetCallback
static void __cdecl ClientMode_RunCallbacks() {
    void* p = SteamProxy::Instance().GetSteamClientObj();
    if (!p) return;
    void** vt = *(void***)p;
    typedef void (__thiscall *RunFrameFn)(void*);
    ((RunFrameFn)vt[20])(p);
    // Диспетчеризация колбэков через C-экспорты steamclient:
    typedef int (__cdecl *BGetCallbackFn)(int, void*, void*);
    typedef void (__cdecl *FreeLastFn)(int);
    BGetCallbackFn bget = (BGetCallbackFn)::GetProcAddress(SteamProxy::Instance().GetSteamClientModule(), "Steam_BGetCallback");
    FreeLastFn freecb = (FreeLastFn)::GetProcAddress(SteamProxy::Instance().GetSteamClientModule(), "Steam_FreeLastCallback");
    if (!bget || !freecb) return;
    // CallbackMsg_t { HSteamPipe m_hPipe; int m_iCallback; uint8* m_pubParam; int m_cubParam; }
    struct { int pipe; int id; unsigned char* data; int size; } msg;
    void* callHandle = nullptr;
    while (bget(1, &msg, &callHandle)) {
        diag::log("  callback dispatch id=%d size=%d", msg.id, msg.size);
        SteamProxy::Instance().DispatchCallback(msg.id, msg.data, msg.size);
        freecb(1);
    }
}

// Регистрация колбэка движка в наш реестр (аналог Valve)
static void __cdecl ClientMode_RegisterCallback(void* cb, int id) {
    SteamProxy::Instance().RegisterCallback(cb, id);
}

void* SteamProxy::GetOriginal(const char* funcName) {
    // Ленивая загрузка: колбэки регистрируются ДО SteamAPI_Init, поэтому прокси
    // может быть ещё не загружен на момент первого GetOriginal.
    if (!m_bSteamLoaded) Init();
    if (!m_bSteamLoaded || !m_hSteamAPI || !funcName) return nullptr;
    // В steamclient-режиме эмулируем жизненный цикл: Init/Shutdown/RunCallbacks
    // не нужны ( steamclient сам крутит свой цикл ), интерфейсы берём по версиям.
    if (m_bSteamClientMode) {
        // steamclient-режим: жизненный цикл эмулируем локальными заглушками-ФУНКЦИЯМИ
        // (НЕ маркерами! движок вызывает возвращённые адреса как код).
        if (strcmp(funcName, "SteamAPI_Init") == 0) return (void*)&ClientMode_Init;
        if (strcmp(funcName, "SteamAPI_Shutdown") == 0) return (void*)&ClientMode_Void;
        if (strcmp(funcName, "SteamAPI_RunCallbacks") == 0) return (void*)&ClientMode_RunCallbacks;
        if (strcmp(funcName, "SteamAPI_RegisterCallback") == 0) return (void*)&ClientMode_RegisterCallback;
        if (strcmp(funcName, "SteamAPI_RegisterCallResult") == 0) return (void*)&ClientMode_Void;
        if (strcmp(funcName, "SteamClient") == 0) return (void*)&ClientMode_Void;
        if (strcmp(funcName, "GetHSteamPipe") == 0) return (void*)&ClientMode_Handle1;
        if (strcmp(funcName, "GetHSteamUser") == 0) return (void*)&ClientMode_Handle1;
        // SteamAPI_GetHSteamPipe/User — аналогичные хэндлы
        if (strcmp(funcName, "SteamAPI_GetHSteamPipe") == 0) return (void*)&ClientMode_Handle1;
        if (strcmp(funcName, "SteamAPI_GetHSteamUser") == 0) return (void*)&ClientMode_Handle1;
        // SteamAPI_* -> Steam_* маппинг на C-экспорты steamclient.dll
        // (именно эти Steam_* функции Valve steam_api.dll дергает внутри себя)
        if (strcmp(funcName, "SteamAPI_ISteamUser_InitiateGameConnection") == 0)
            return (void*)::GetProcAddress(m_hSteamAPI, "Steam_InitiateGameConnection");
        if (strcmp(funcName, "SteamAPI_ISteamUser_TerminateGameConnection") == 0)
            return (void*)::GetProcAddress(m_hSteamAPI, "Steam_TerminateGameConnection");
        if (strncmp(funcName, "SteamAPI_ISteam", 15) == 0)
            return (void*)&ClientMode_Void;
        return nullptr;
    }
    return (void*)::GetProcAddress(m_hSteamAPI, funcName);
}

void* SteamProxy::GetClientCreateInterface() {
    if (!m_bSteamLoaded || !m_hSteamAPI) return nullptr;
    return (void*)::GetProcAddress(m_hSteamAPI, "CreateInterface");
}
void SteamProxy::SetSteamClientObj(void* p) { m_pSteamClientObj = p; }
void* SteamProxy::GetSteamClientObj() { return m_pSteamClientObj; }

// Callback registry (ядро Valve steam_api.dll): движок регистрирует колбэки (объект+ID),
// RunCallbacks диспатчит события steamclient по совпадению ID.
void SteamProxy::RegisterCallback(void* cb, int id) {
    m_callbacks.push_back({cb, id});
    diag::log("callback registered cb=%p id=%d (total=%d)", cb, id, (int)m_callbacks.size());
}
void SteamProxy::DispatchCallback(int id, void* data, int size) {
    for (auto& e : m_callbacks) {
        if (e.id != id) continue;
        // CCallbackBase vtable: [0]=Run(pvParam)  thiscall
        void** vt = *(void***)e.cb;
        typedef void (__thiscall *RunFn)(void*, void*);
        ((RunFn)vt[0])(e.cb, data);
    }
}