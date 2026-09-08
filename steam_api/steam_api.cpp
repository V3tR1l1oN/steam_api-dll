#include "..\public\steam\steam_api_goldsrc.h"
#include <string.h>

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

static void* SteamInternal_CreateInterface(const char* name) {
    if (!name) return nullptr;
    return nullptr;
}

extern "C" {
    void* CreateInterface(const char* name, int* return_code) {
        return SteamInternal_CreateInterface(name);
    }
    __declspec(dllexport) void* SteamInternal_FindOrCreateUserInterface(void* h, const char* v) {
        return &s_SteamClient;
    }
    __declspec(dllexport) void* SteamInternal_FindOrCreateGameServerInterface(void* h, const char* v) {
        return &s_SteamClient;
    }
    __declspec(dllexport) void* SteamInternal_ContextInit(void* ctx) { return nullptr; }
    __declspec(dllexport) bool SteamAPI_Init() {
        LargeDummyFunction();
        return true;
    }
    __declspec(dllexport) void SteamAPI_Shutdown() {}
    __declspec(dllexport) void SteamAPI_RunCallbacks() {}
    __declspec(dllexport) void* SteamClient() { return &s_SteamClient; }
    void* SteamGameServer() { return &s_SteamClient; }
    void* SteamGameServer_Init() { return (void*)1; }
    __declspec(dllexport) void SteamGameServer_Shutdown() {}
    __declspec(dllexport) void* SteamGameServer_GetHSteamPipe() { return (void*)1; }
    __declspec(dllexport) void* SteamGameServer_GetHSteamUser() { return (void*)1; }
    __declspec(dllexport) void* SteamGameServer_GetSteamID() { return (void*)0x110000100001; }
    __declspec(dllexport) void* SteamGameServer_InitSafe() { return (void*)1; }
    __declspec(dllexport) void* SteamGameServer_RunCallbacks() { return nullptr; }
    __declspec(dllexport) int SteamGameServer_BSecure() { return 0; }
    __declspec(dllexport) void* g_pSteamClientGameServer = nullptr;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        DummyFunc01();
        DummyFunc02();
        DummyFunc03();
        DummyFunc04();
        DummyFunc05();
        DummyFunc06();
        DummyFunc07();
        DummyFunc08();
        DummyFunc09();
        DummyFunc10();
        DummyFunc11();
        DummyFunc12();
        DummyFunc13();
        DummyFunc14();
        DummyFunc15();
        DummyFunc16();
        DummyFunc17();
        DummyFunc18();
        DummyFunc19();
        DummyFunc20();
        volatile const char* p = g_text_padding;
        volatile const char* q = g_rdata_padding;
        (void)p;
        (void)q;
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
