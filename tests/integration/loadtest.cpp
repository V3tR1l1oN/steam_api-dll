#include <windows.h>
#include <stdio.h>
#include <string>
int main(int argc, char** argv) {
    char selfDir[MAX_PATH] = {0};
    std::string dllPath;
    if (argc > 1) {
        dllPath = argv[1];
    } else {
        GetModuleFileNameA(NULL, selfDir, MAX_PATH);
        std::string dir = selfDir;
        size_t p = dir.find_last_of("\\/");
        if (p != std::string::npos) dir = dir.substr(0, p + 1);
        dllPath = dir + "..\\..\\build\\Release\\steam_api.dll";
    }
    HMODULE h = LoadLibraryA(dllPath.c_str());
    if (!h) { printf("FAIL: LoadLibrary(%s) error %lu\n", dllPath.c_str(), GetLastError()); return 1; }
    printf("LOAD OK: %s\n", dllPath.c_str());

    const char* required[] = {
        "SteamAPI_Init", "SteamAPI_Shutdown", "SteamAPI_RunCallbacks",
        "SteamClient", "GetHSteamPipe", "GetHSteamUser",
        "SteamInternal_CreateInterface", "SteamInternal_FindOrCreateUserInterface",
        "SteamAPI_ISteamClient_GetISteamUser", "SteamAPI_ISteamClient_GetISteamFriends",
        "SteamAPI_ISteamClient_GetISteamUtils", "SteamAPI_ISteamClient_GetISteamApps",
        "SteamAPI_ISteamClient_GetISteamNetworking", "SteamAPI_ISteamClient_GetISteamMatchmaking",
        "SteamAPI_ISteamClient_GetISteamUserStats", "SteamAPI_ISteamUser_GetSteamID",
        "SteamAPI_ISteamApps_BIsSubscribed", "SteamAPI_ISteamUtils_GetAppID",
        "SteamGameServer_BSecure", "g_pSteamClientGameServer",
    };
    int failed = 0;
    for (int i = 0; i < (int)(sizeof(required)/sizeof(required[0])); i++) {
        if (!GetProcAddress(h, required[i])) { printf("MISSING EXPORT: %s\n", required[i]); failed++; }
    }
    if (!failed) printf("ALL KEY EXPORTS PRESENT\n");
    FreeLibrary(h);
    printf(failed ? "RESULT: FAIL\n" : "RESULT: ALL OK\n");
    return failed ? 1 : 0;
}
