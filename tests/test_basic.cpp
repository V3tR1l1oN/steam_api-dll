#include <windows.h>
#include <stdio.h>
#include "..\public\steam\steam_api_goldsrc.h"

typedef void* (*CreateInterfaceFn)(const char* name);

int main() {
    HMODULE h = LoadLibraryA("build\\steam_api.dll");
    if (!h) { printf("FAIL: LoadLibrary (error %lu)\n", GetLastError()); return 1; }

    CreateInterfaceFn ci = (CreateInterfaceFn)GetProcAddress(h, "SteamInternal_CreateInterface");
    if (!ci) { printf("FAIL: SteamInternal_CreateInterface not found\n"); return 1; }

    printf("SteamInternal_CreateInterface -> %p\n", ci);
    printf("GetHSteamPipe -> %p\n", GetProcAddress(h, "GetHSteamPipe"));
    printf("SteamClient -> %p\n", GetProcAddress(h, "SteamClient"));
    printf("SteamAPI_Init -> %p\n", GetProcAddress(h, "SteamAPI_Init"));

    printf("OK\n");
    return 0;
}
