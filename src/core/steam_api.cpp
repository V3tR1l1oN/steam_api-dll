#include "../../include/steam/steam_api_goldsrc.h"
#include <string.h>
#include "proxy.h"
#include "diag_log.h"
#include "../interfaces/steam_user.h"
#include "../interfaces/steam_friends.h"
#include "../interfaces/steam_utils.h"
#include "../interfaces/steam_apps.h"
#include "../interfaces/steam_networking.h"
#include "../interfaces/steam_matchmaking.h"
#include "../interfaces/steam_userstats.h"
#include "../interfaces/steam_music.h"
#include "../interfaces/sdk_guard.h"
#include "../interfaces/sdk_client.h"
#include "../interfaces/vproxy.h"

// VEH: логирует точный адрес сбоя при краше в процессе игры
static long __stdcall CrashHandler(PEXCEPTION_POINTERS ep) {
    if (ep && ep->ExceptionRecord && ep->ExceptionRecord->ExceptionCode == 0xC0000005) {
        HMODULE hMod = nullptr;
        char modName[MAX_PATH] = {0};
        if (ep && ep->ExceptionRecord && GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
            (LPCSTR)ep->ExceptionRecord->ExceptionAddress, &hMod)) {
            GetModuleFileNameA(hMod, modName, MAX_PATH);
        }
        diag::logContext(ep);
        diag::log("!!! ACCESS VIOLATION: pc=%p addr=%p rw=%d module=%s",
            ep->ExceptionRecord->ExceptionAddress,
            ep->ExceptionRecord->ExceptionInformation[1],
            (int)ep->ExceptionRecord->ExceptionInformation[0], modName);
        diag::close();
    }
    return EXCEPTION_CONTINUE_SEARCH;
}
static PVOID g_veh = nullptr;
#include "../interfaces/steam_networking_sockets.h"
#include "../interfaces/steam_networking_messages.h"

class InputInternal001;
class Localize003;
class Scheme009;
class Surface026;
class System009;
class IVGui006;
class KeyValues003;
class Panel007;

extern InputInternal001 g_InputInternal001;
extern InputInternal001 g_Input004;
extern Localize003 g_Localize003;
extern Localize003 g_Localize002;
extern Scheme009 g_Scheme009;
extern Surface026 g_Surface026;
extern System009 g_System009;
extern IVGui006 g_IVGui006;
extern KeyValues003 g_KeyValues003;
extern Panel007 g_Panel007;

extern "C" {
    extern void DummyFunc01();
    extern void DummyFunc02();
    extern void DummyFunc03();
    extern void DummyFunc04();
    extern void DummyFunc05();
    extern void DummyFunc06();
    extern void DummyFunc07();
    extern void DummyFunc08();
    extern void DummyFunc09();
    extern void DummyFunc10();
    extern void DummyFunc11();
    extern void DummyFunc12();
    extern void DummyFunc13();
    extern void DummyFunc14();
    extern void DummyFunc15();
    extern void DummyFunc16();
    extern void DummyFunc17();
    extern void DummyFunc18();
    extern void DummyFunc19();
    extern void DummyFunc20();
    extern void LargeDummyFunction();
    extern const char g_text_padding[];
    extern const char g_rdata_padding[];
}

CSteamClient s_SteamClient;

#pragma code_seg(".text")
extern "C" {
    __declspec(allocate(".text")) const char g_text_padding[110928] = {0xCC};
}
#pragma code_seg()

#pragma data_seg(".rdata")
extern "C" {
    __declspec(allocate(".rdata")) const char g_rdata_padding[24576] = {0};
}
#pragma data_seg()

CSteamUser s_SteamUser;
CSteamFriends s_SteamFriends;
CSteamUtils s_SteamUtils;
CSteamApps s_SteamApps;
CSteamNetworking s_SteamNetworking;
CSteamMatchmaking s_SteamMatchmaking;
CSteamUserStats s_SteamUserStats;
CSteamAppList s_SteamAppList;
CSteamController s_SteamController;
CSteamHTMLSurface s_SteamHTMLSurface;
CSteamHTTP s_SteamHTTP;
CSteamInput s_SteamInput;
CSteamInventory s_SteamInventory;
CSteamMatchmakingClient s_SteamMatchmakingClient;
CSteamMatchmakingServers s_SteamMatchmakingServers;
CSteamMusic s_SteamMusic;
CSteamNetworkingSockets s_SteamNetworkingSockets;
CSteamNetworkingMessages s_SteamNetworkingMessages;
CSteamNetworkingUtils s_SteamNetworkingUtils;
CSteamParentalSettings s_SteamParentalSettings;
CSteamParties s_SteamParties;
CSteamRemotePlay s_SteamRemotePlay;
CSteamRemoteStorage s_SteamRemoteStorage;
CSteamScreenshots s_SteamScreenshots;
CSteamUGC s_SteamUGC;
CSteamVideo s_SteamVideo;

// Vtable-совместимые с Valve объекты для оффлайн-контекста
static SdkSteamClient s_SdkClient;
static SdkSteamUser s_SdkUser;
static SdkSteamFriends s_SdkFriends;
static SdkSteamApps s_SdkApps;
static SdkSteamUserStats s_SdkUserStats;
static SdkSteamNetworking s_SdkNetworking;

static void* SteamInternal_CreateInterface(const char* name) {
    diag::log("static CreateInterface: %s", name ? name : "(null)");
    if (!name) return nullptr;
    return nullptr;
}

extern "C" {
    __declspec(dllexport) void* CreateInterface(const char* name, int* return_code) {
        diag::log("export CreateInterface: %s", name ? name : "(null)");
        return SteamInternal_CreateInterface(name);
    }
    __declspec(dllexport) void* SteamInternal_FindOrCreateUserInterface(void* h, const char* v) {
        diag::log("FindOrCreateUserInterface h=%p v=%s", h, v ? v : "(null)");
        if (SteamProxy::Instance().IsSteamClientMode()) {
            // steamclient-режим: интерфейсы напрямую из ядра Steam по версии
            auto ci = (void*(*)(const char*, int*))SteamProxy::Instance().GetClientCreateInterface();
            if (ci) {
                int rc = 0;
                void* r = ci(v, &rc);
                diag::log("  -> steamclient CreateInterface(%s) = %p rc=%d", v ? v : "?", r, rc);
                return r;
            }
            diag::log("  -> steamclient CreateInterface not found");
            return nullptr;
        }
        auto orig = (void*(*)(void*, const char*))SteamProxy::Instance().GetOriginal("SteamInternal_FindOrCreateUserInterface");
        if (orig) { void* r = orig(h, v); diag::log("  -> orig=%p", r); return r; }
        // Оффлайн: по версии строки выбираем vtable-совместимый объект
        if (v) {
            if (strncmp(v, "SteamUser0", 10) == 0) { void* r = &s_SdkUser; diag::log("  -> offline SdkUser %p", r); return r; }
            if (strncmp(v, "SteamFriends", 12) == 0) { void* r = &s_SdkFriends; diag::log("  -> offline SdkFriends %p", r); return r; }
            if (strncmp(v, "SteamUtils", 10) == 0) { void* r = &s_SteamUtils; diag::log("  -> offline Utils %p", r); return r; }
            if (strncmp(v, "STEAMAPPS", 9) == 0) { void* r = &s_SdkApps; diag::log("  -> offline SdkApps %p", r); return r; }
            if (strncmp(v, "SteamMatchmaking", 16) == 0) { void* r = &s_SteamMatchmaking; diag::log("  -> offline MM %p", r); return r; }
            if (strncmp(v, "STEAMUSERSTATS", 14) == 0 || strncmp(v, "SteamUserStats", 14) == 0) { void* r = &s_SdkUserStats; diag::log("  -> offline Stats %p", r); return r; }
            if (strncmp(v, "SteamNetworkingSockets", 22) == 0) { void* r = &s_SdkNetworking; diag::log("  -> offline Net %p", r); return r; }
        }
        void* d = &s_SdkUser; diag::log("  -> offline default User %p", d); return d;
    }
    __declspec(dllexport) void* SteamInternal_FindOrCreateGameServerInterface(void* h, const char* v) {
        diag::log("FindOrCreateGameServerInterface h=%p v=%s", h, v ? v : "(null)");
        auto orig = (void*(*)(void*, const char*))SteamProxy::Instance().GetOriginal("SteamInternal_FindOrCreateGameServerInterface");
        if (orig) { void* r = orig(h, v); diag::log("  -> orig=%p", r); return r; }
        void* r = &s_SdkUser; diag::log("  -> offline default (gs) %p", r); return r;
    }
    // Универсальная заглушка: движок может вызывать любой слот контекста как функцию
    // с любыми аргументами. cdecl — стек чистит вызывающий, так что пустое тело безопасно.
    static void __cdecl OfflineContextStub() {}

    // Оффлайн-контекст: таблица function pointers движка. Заполняем все слоты
    // универсальной заглушкой, ключевые — интерфейсными объектами.
    static void* s_offlineContext[64];
    static bool s_offlineContextInit = false;
    static void InitOfflineContext() {
        if (s_offlineContextInit) return;
        for (int i = 0; i < 64; ++i) s_offlineContext[i] = (void*)&OfflineContextStub;
        // CSteamAPIContext (из steam_api.h SDK): первый элемент — ISteamUser.
        // Движок читает слот 0 и вызывает vtable[1] (BLoggedOn) без аргументов.
        s_offlineContext[0]  = &s_SdkUser;
        s_offlineContext[1]  = &s_SdkFriends;
        s_offlineContext[2]  = &s_SteamUtils;
        s_offlineContext[3]  = &s_SteamMatchmaking;
        s_offlineContext[4]  = &s_SdkUserStats;
        s_offlineContext[5]  = &s_SdkApps;
        s_offlineContext[6]  = &s_SdkNetworking;
        s_offlineContext[7]  = nullptr;
        s_offlineContext[8]  = &s_SteamMusic;
        s_offlineContextInit = true;
    }
    __declspec(dllexport) void* SteamInternal_ContextInit(void* ctx) {
        diag::log("SteamInternal_ContextInit ctx=%p", ctx);
        auto orig = (void*(*)(void*))SteamProxy::Instance().GetOriginal("SteamInternal_ContextInit");
        if (orig) { void* r = orig(ctx); diag::log("  -> orig=%p", r); return r; }
        // ДИЗАСЕМБЛЕР hw.dll раскрыл раскладку: в .data движка лежат ТРИ структуры,
        // подряд по 12 байт (3 слота): 0x...D274, 0x...D280, 0x...D28C.
        // Движок вызывает ContextInit(адрес_одной_из_них) и затем читает слоты [0..2]:
        //   D274[0].vtable[0] и [1] — вызовы без аргументов (ISteamUser: GetHSteamUser/BLoggedOn)
        //   D280[0].vtable[46] — вызов с аргументом (ISteamNetworkingSockets012: CreateFakeUDPPort)
        //   D28C[0].vtable[0]  — вызов без аргументов
        // КРИТИЧНО: писать можно ТОЛЬКО 3 слота (12 байт) — дальше лежат данные/коды движка!
        InitOfflineContext();
        void** pCtxSlots = (void**)ctx;
        if (ctx && SteamProxy::Instance().IsSteamClientMode()) {
            // steamclient-режим: ISteamClient021 → CreateSteamPipe → ConnectToGlobalUser
            // → GetISteamUser/Friends/Utils. Движок получает НАСТОЯЩИЕ интерфейсы.
            auto ci = (void*(*)(const char*, int*))SteamProxy::Instance().GetClientCreateInterface();
            void* client = ci ? ci("SteamClient021", nullptr) : nullptr;
            diag::log("  steamclient client=%p", client);
            SteamProxy::Instance().SetSteamClientObj(client);
            if (client) {
                // Проверка авторизации процесса в Steam
                auto blogged = (bool(*)())::GetProcAddress(SteamProxy::Instance().GetSteamClientModule(), "Steam_BLoggedOn");
                auto bconn = (bool(*)())::GetProcAddress(SteamProxy::Instance().GetSteamClientModule(), "Steam_BConnected");
                diag::log("  steamclient BLoggedOn=%d BConnected=%d",
                    blogged ? (int)blogged() : -1, bconn ? (int)bconn() : -1);
                void** vt = *(void***)client;
                typedef int (__thiscall *CreatePipeFn)(void*);
                typedef int (__thiscall *ConnectFn)(void*, int);
                typedef void* (__thiscall *GetIfaceFn)(void*, int, int, const char*);
                int hPipe = ((CreatePipeFn)vt[0])(client);
                int hUser = ((ConnectFn)vt[2])(client, hPipe);
                diag::log("  steamclient pipe=%d user=%d", hPipe, hUser);
                // ISteamClient021 vtable: [5]GetISteamUser [8]GetISteamFriends [9]GetISteamUtils
                // VPROXY: лог-прокси вместо реального user — отловим call 0x0
                pCtxSlots[0] = vproxy::GetProxyUserObj();
                pCtxSlots[1] = ((GetIfaceFn)vt[8])(client, hUser, hPipe, "SteamFriends017");
                typedef void* (__thiscall *GetUtilsFn)(void*, int, const char*);
                pCtxSlots[2] = ((GetUtilsFn)vt[9])(client, hPipe, "SteamUtils010");
                diag::log("  steamclient: user=%p friends=%p utils=%p",
                    pCtxSlots[0], pCtxSlots[1], pCtxSlots[2]);
                // ISteamClient021 vtable: [10]GetISteamMatchmaking [13]GetISteamUserStats
                // [15]GetISteamApps
                typedef void* (__thiscall *GetMMFn)(void*, int, int, const char*);
                pCtxSlots[3] = ((GetMMFn)vt[10])(client, hUser, hPipe, "SteamMatchmaking009");
                if (!pCtxSlots[3]) {
                    // Matchmaking может отсутствовать в текущем steamclient —
                    // отдаём наш SDK-совместимый оффлайн-объект (лобби локальные)
                    pCtxSlots[3] = &s_SteamMatchmaking;
                    diag::log("  mm NULL -> offline matchmaking");
                }
                pCtxSlots[4] = ((GetIfaceFn)vt[13])(client, hUser, hPipe, "STEAMUSERSTATS_INTERFACE_VERSION012");
                pCtxSlots[5] = ((GetIfaceFn)vt[15])(client, hUser, hPipe, "STEAMAPPS_INTERFACE_VERSION008");
                diag::log("  steamclient: mm=%p stats=%p apps=%p",
                    pCtxSlots[3], pCtxSlots[4], pCtxSlots[5]);
            }
        }
        if (ctx) {
            // ЭМУЛЯЦИЯ CALLBACK FLOW VALVE: движок после ContextInit ждёт, что
            // интерфейсы были созданы через FindOrCreateUserInterface — при этом
            // инициализируются подсистемы движка. Вызываем наш экспорт для
            // каждого интерфейса (он отдаёт наши SDK-совместимые объекты).
            void* pUser    = SteamInternal_FindOrCreateUserInterface((void*)1, "SteamUser023");
            void* pFriends = SteamInternal_FindOrCreateUserInterface((void*)1, "SteamFriends017");
            void* pUtils   = SteamInternal_FindOrCreateUserInterface((void*)1, "SteamUtils010");
            void* pMM      = SteamInternal_FindOrCreateUserInterface((void*)1, "SteamMatchmaking009");
            void* pStats   = SteamInternal_FindOrCreateUserInterface((void*)1, "STEAMUSERSTATS_INTERFACE_VERSION012");
            void* pApps    = SteamInternal_FindOrCreateUserInterface((void*)1, "STEAMAPPS_INTERFACE_VERSION008");
            diag::log("  flow: user=%p friends=%p utils=%p mm=%p stats=%p apps=%p",
                pUser, pFriends, pUtils, pMM, pStats, pApps);
            // GetHSteamUser вызвался — движок идёт по слотам ПОДРЯД (CSteamAPIContext):
            // [0] ISteamUser, [1] ISteamFriends, [2] ISteamUtils, [3] ISteamMatchmaking,
            // [4] ISteamUserStats, [5] ISteamApps, [6] ISteamNetworking.
            // NULL-слот = вызов по нулю, поэтому ВСЕ слоты — валидные объекты.
            pCtxSlots[0] = vproxy::GetProxyUserObj(); // LOG: отловим какой слот вызывает 0x0
            pCtxSlots[1] = pFriends;
            pCtxSlots[2] = pUtils;
            pCtxSlots[3] = pMM;
            pCtxSlots[4] = pStats;
            pCtxSlots[5] = pApps;
            pCtxSlots[6] = &s_SdkNetworking;
            // Стек-резолв показал: движок вызывает и слоты дальше [6] через
            // CSteamAPIContext-подобную структуру (RemoteStorage, Screenshots,
            // HTTP, Controller, UGC, AppList, Music, Video, Inventory, ...).
            // Заполняем до 16 слотов нашими объектами, чтобы ни один вызов
            // не ушёл в NULL.
            pCtxSlots[7]  = &s_SdkApps;          // RemoteStorage
            pCtxSlots[8]  = &s_SdkApps;          // Screenshots
            pCtxSlots[9]  = &s_SdkApps;          // HTTP
            pCtxSlots[10] = &s_SdkApps;          // Controller
            pCtxSlots[11] = &s_SdkApps;          // UGC
            pCtxSlots[12] = &s_SdkApps;          // AppList
            pCtxSlots[13] = &s_SteamMusic;       // Music
            pCtxSlots[14] = &s_SdkApps;          // MusicRemote
            pCtxSlots[15] = &s_SdkApps;          // HTMLSurface
            diag::log("  -> filled 16 slots of engine ctx at %p", ctx);
        }
        return ctx;
    }
    __declspec(dllexport) bool SteamAPI_Init() {
        diag::log("SteamAPI_Init called");
        if (SteamProxy::Instance().Init()) {
            auto orig = (bool(*)())SteamProxy::Instance().GetOriginal("SteamAPI_Init");
            diag::log("proxy loaded, orig SteamAPI_Init=%p", orig);
            if (orig) { bool r = orig(); diag::log("orig SteamAPI_Init -> %d", (int)r); return r; }
        } else {
            diag::log("proxy NOT loaded (no steam_api_orig.dll), using offline mode");
        }
        LargeDummyFunction();
        diag::log("SteamAPI_Init -> 1 (offline)");
        return true;
    }
    __declspec(dllexport) void SteamAPI_Shutdown() {
        diag::log("SteamAPI_Shutdown called");
        if (SteamProxy::Instance().IsSteamLoaded()) {
            auto orig = (void(*)())SteamProxy::Instance().GetOriginal("SteamAPI_Shutdown");
            if (orig) { orig(); return; }
        }
    }
    __declspec(dllexport) void SteamAPI_RunCallbacks() {
        diag::log("call: SteamAPI_RunCallbacks enter");
        if (SteamProxy::Instance().IsSteamLoaded()) {
            auto orig = (void(*)())SteamProxy::Instance().GetOriginal("SteamAPI_RunCallbacks");
            if (orig) { orig(); return; }
        }
    }
    __declspec(dllexport) void* SteamClient() {
        if (SteamProxy::Instance().IsSteamLoaded()) {
            auto orig = (void*(*)())SteamProxy::Instance().GetOriginal("SteamClient");
            diag::log("SteamClient: proxy -> %p", orig);
            if (orig) return orig();
        }
        diag::log("SteamClient: offline -> %p", (void*)&s_SteamClient);
        return &s_SteamClient;
    }
    __declspec(dllexport) void* GetHSteamPipe() {
        diag::log("exp: GetHSteamPipe");
        if (SteamProxy::Instance().IsSteamLoaded()) {
            auto orig = (void*(*)())SteamProxy::Instance().GetOriginal("GetHSteamPipe");
            if (orig) return orig();
        }
        return (void*)1;
    }
    __declspec(dllexport) void* GetHSteamUser() {
        diag::log("exp: GetHSteamUser");
        if (SteamProxy::Instance().IsSteamLoaded()) {
            auto orig = (void*(*)())SteamProxy::Instance().GetOriginal("GetHSteamUser");
            if (orig) return orig();
        }
        return (void*)1;
    }
    void* SteamGameServer() { diag::log("call: SteamGameServer"); return &s_SteamClient; }
    void* SteamGameServer_Init() { diag::log("call: SteamGameServer_Init (stub, not forwarded - hw.dll uses SteamInternal_GameServer_Init)"); return (void*)1; }
    __declspec(dllexport) void SteamGameServer_Shutdown() {}
    __declspec(dllexport) void* SteamGameServer_GetHSteamPipe() { diag::log("call: SteamGameServer_GetHSteamPipe"); return (void*)1; }
    __declspec(dllexport) void* SteamGameServer_GetHSteamUser() { diag::log("call: SteamGameServer_GetHSteamUser"); return (void*)1; }
    __declspec(dllexport) void* SteamGameServer_GetSteamID() { return (void*)0x110000100001; }
    __declspec(dllexport) void* SteamGameServer_InitSafe() { diag::log("call: SteamGameServer_InitSafe (stub)"); return (void*)1; }
    __declspec(dllexport) void* SteamGameServer_RunCallbacks() { return nullptr; }
    __declspec(dllexport) int SteamGameServer_BSecure() { return 0; }
    __declspec(dllexport) void* g_pSteamClientGameServer = nullptr;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        diag::open();
        diag::log("=== DllMain ATTACH, module=%p ===", (void*)hModule);
        g_veh = AddVectoredExceptionHandler(1, CrashHandler);
        diag::log("padding refs ok");
    } else if (ul_reason_for_call == DLL_PROCESS_DETACH) {
        diag::log("=== DllMain DETACH ===");
        if (g_veh) { RemoveVectoredExceptionHandler(g_veh); g_veh = nullptr; }
        diag::close();
    }
    return TRUE;
}

ISteamUser* CSteamClient::GetISteamUser(HSteamUser hSteamUser, const char* pchVersion) {
    return &s_SteamUser;
}

ISteamFriends* CSteamClient::GetISteamFriends(HSteamUser hSteamUser, const char* pchVersion) {
    return &s_SteamFriends;
}

ISteamUtils* CSteamClient::GetISteamUtils(const char* pchVersion) {
    return &s_SteamUtils;
}

ISteamApps* CSteamClient::GetISteamApps(const char* pchVersion) {
    return &s_SteamApps;
}

ISteamNetworking* CSteamClient::GetISteamNetworking(HSteamUser hSteamUser, const char* pchVersion) {
    return &s_SteamNetworking;
}

ISteamMatchmaking* CSteamClient::GetISteamMatchmaking(HSteamUser hSteamUser, const char* pchVersion) {
    return &s_SteamMatchmaking;
}

ISteamUserStats* CSteamClient::GetISteamUserStats(HSteamUser hSteamUser, const char* pchVersion) {
    return &s_SteamUserStats;
}
