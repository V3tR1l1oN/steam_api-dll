#include "proxy.h"
#include <vector>

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
    GetModuleFileNameA((HMODULE)&SteamProxy::Instance, selfPath, MAX_PATH);
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
            return true;
        }
    }

    return false;
}

void SteamProxy::Shutdown() {
    if (m_hSteamAPI) {
        FreeLibrary(m_hSteamAPI);
        m_hSteamAPI = nullptr;
    }
    m_bSteamLoaded = false;
}

void* SteamProxy::GetOriginal(const char* funcName) {
    // Ленивая загрузка: колбэки регистрируются ДО SteamAPI_Init, поэтому прокси
    // может быть ещё не загружен на момент первого GetOriginal.
    if (!m_bSteamLoaded) Init();
    if (!m_bSteamLoaded || !m_hSteamAPI || !funcName) return nullptr;
    return (void*)::GetProcAddress(m_hSteamAPI, funcName);
}
