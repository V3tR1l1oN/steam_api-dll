#include <windows.h>
#include <stdio.h>
#include "..\public\steam\steam_api_goldsrc.h"

int main() {
    HMODULE h = LoadLibraryA("build\\steam_api.dll");
    if (!h) { printf("FAIL: LoadLibrary\n"); return 1; }

    typedef void* (*GetISteamMatchmakingFn)(void* h, const char* v);
    GetISteamMatchmakingFn getMM = (GetISteamMatchmakingFn)GetProcAddress(h, "SteamAPI_ISteamClient_GetISteamMatchmaking");
    if (!getMM) { printf("FAIL: GetISteamMatchmaking not found\n"); return 1; }

    ISteamMatchmaking* mm = (ISteamMatchmaking*)getMM((void*)1, "ISteamMatchmaking");
    if (!mm) { printf("FAIL: ISteamMatchmaking null\n"); return 1; }

    printf("ISteamMatchmaking: %p\n", mm);
    printf("GetFavoriteGameCount: %d\n", mm->GetFavoriteGameCount());
    printf("RequestLobbyList done\n");

    typedef void* (*GetISteamUserStatsFn)(void* h, const char* v);
    GetISteamUserStatsFn getStats = (GetISteamUserStatsFn)GetProcAddress(h, "SteamAPI_ISteamClient_GetISteamUserStats");
    if (!getStats) { printf("FAIL: GetISteamUserStats not found\n"); return 1; }

    ISteamUserStats* stats = (ISteamUserStats*)getStats((void*)1, "ISteamUserStats");
    if (!stats) { printf("FAIL: ISteamUserStats null\n"); return 1; }

    printf("ISteamUserStats: %p\n", stats);
    bool req = stats->RequestCurrentStats();
    printf("RequestCurrentStats: %d\n", req);

    printf("OK\n");
    return 0;
}
