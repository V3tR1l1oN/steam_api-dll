#include <windows.h>
#include <stdio.h>
#include "..\public\steam\steam_api_goldsrc.h"

int main() {
    HMODULE h = LoadLibraryA("build\\steam_api.dll");
    if (!h) { printf("FAIL: LoadLibrary\n"); return 1; }

    typedef void* (*CreateInterfaceFn)(const char* name);
    CreateInterfaceFn ci = (CreateInterfaceFn)GetProcAddress(h, "SteamInternal_CreateInterface");

    void* vgui = ci("VGUI_ivgui006");
    printf("VGUI_ivgui006 factory: %p\n", vgui);

    typedef void* (*SteamClientFn)();
    SteamClientFn steamClient = (SteamClientFn)GetProcAddress(h, "SteamClient");
    if (!steamClient) { printf("FAIL: SteamClient\n"); return 1; }

    void* client = steamClient();
    printf("SteamClient: %p\n", client);

    typedef void* (*GetISteamUserFn)(void* h, const char* v);
    GetISteamUserFn getUser = (GetISteamUserFn)GetProcAddress(h, "SteamAPI_ISteamClient_GetISteamUser");
    if (!getUser) { printf("FAIL: GetISteamUser\n"); return 1; }

    ISteamUser* user = (ISteamUser*)getUser((void*)1, "ISteamUser");
    printf("ISteamUser: %p\n", user);

    if (!user) { printf("FAIL: ISteamUser null\n"); return 1; }

    HSteamUser hUser = user->GetHSteamUser();
    printf("GetHSteamUser: %d\n", hUser);

    bool loggedOn = user->BLoggedOn();
    printf("BLoggedOn: %d\n", loggedOn);

    CSteamID steamID = user->GetSteamID();
    printf("GetSteamID: 0x%llx\n", (unsigned long long)steamID);

    printf("OK\n");
    return 0;
}
