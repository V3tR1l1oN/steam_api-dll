#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "..\public\steam\steam_api_goldsrc.h"

typedef void* (*CreateInterfaceFn)(const char* name);

int main() {
    HMODULE h = LoadLibraryA("build\\steam_api.dll");
    if (!h) { printf("FAIL: LoadLibrary\n"); return 1; }

    CreateInterfaceFn ci = (CreateInterfaceFn)GetProcAddress(h, "SteamInternal_CreateInterface");
    if (!ci) { printf("FAIL: SteamInternal_CreateInterface not found\n"); return 1; }

    const char* tests[] = {
        "VGUI_InputInternal001",
        "VGUI_Input004",
        "VGUI_Localize003",
        "VGUI_Localize002",
        "VGUI_Scheme009",
        "VGUI_Surface026",
        "VGUI_System009",
        "VGUI_ivgui006",
        "KeyValues003",
        "VGUI_Panel007",
        NULL
    };

    int passed = 0, failed = 0;
    for (int i = 0; tests[i]; i++) {
        void* v = ci(tests[i]);
        printf("CreateInterface: %s -> %p\n", tests[i], v);
        passed++;
    }

    void* steamClient = GetProcAddress(h, "SteamClient");
    void* steamInit = GetProcAddress(h, "SteamAPI_Init");
    void* getHSteamPipe = GetProcAddress(h, "GetHSteamPipe");

    if (steamClient) printf("PASS: SteamClient -> %p\n", steamClient); else { printf("FAIL: SteamClient missing\n"); failed++; }
    if (steamInit) printf("PASS: SteamAPI_Init -> %p\n", steamInit); else { printf("FAIL: SteamAPI_Init missing\n"); failed++; }
    if (getHSteamPipe) printf("PASS: GetHSteamPipe -> %p\n", getHSteamPipe); else { printf("FAIL: GetHSteamPipe missing\n"); failed++; }

    printf("\nResult: %d passed, %d failed\n", passed, failed);
    return failed ? 1 : 0;
}
