#include <windows.h>
#include <stdio.h>
#include "..\public\steam\steam_api_goldsrc.h"

int main() {
    HMODULE h = LoadLibraryA("build\\steam_api.dll");
    if (!h) { printf("FAIL: LoadLibrary\n"); return 1; }

    typedef void* (*GetISteamFriendsFn)(void* h, const char* v);
    GetISteamFriendsFn getFriends = (GetISteamFriendsFn)GetProcAddress(h, "SteamAPI_ISteamClient_GetISteamFriends");
    if (!getFriends) { printf("FAIL: GetISteamFriends not found\n"); return 1; }

    ISteamFriends* friends = (ISteamFriends*)getFriends((void*)1, "ISteamFriends");
    if (!friends) { printf("FAIL: ISteamFriends null\n"); return 1; }

    printf("ISteamFriends: %p\n", friends);
    printf("GetPersonaName: %s\n", friends->GetPersonaName());
    printf("GetPersonaState: %d\n", friends->GetPersonaState());
    printf("GetFriendCount: %d\n", friends->GetFriendCount(0));

    typedef void* (*GetISteamAppsFn)(const char* v);
    GetISteamAppsFn getApps = (GetISteamAppsFn)GetProcAddress(h, "SteamAPI_ISteamClient_GetISteamApps");
    if (!getApps) { printf("FAIL: GetISteamApps not found\n"); return 1; }

    ISteamApps* apps = (ISteamApps*)getApps("ISteamApps");
    if (!apps) { printf("FAIL: ISteamApps null\n"); return 1; }

    printf("ISteamApps: %p\n", apps);
    printf("BIsSubscribed: %d\n", apps->BIsSubscribed());
    printf("GetAppName: %s\n", apps->GetAppName());
    printf("GetCurrentGameLanguage: %s\n", apps->GetCurrentGameLanguage());

    printf("OK\n");
    return 0;
}
