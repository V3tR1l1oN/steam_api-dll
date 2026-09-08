// steam_api_goldsrc.h - Steam API public header
// Clean-room reconstruction for GoldSrc

#pragma once

#ifdef STEAM_API_EXPORTS
#define STEAM_API __declspec(dllexport)
#else
#define STEAM_API __declspec(dllimport)
#endif

// Steam handles
typedef int HSteamPipe;
typedef int HSteamUser;
typedef int HSteamGlobalUser;

// Steam callback results
enum ESteamAPICallResult {
    k_STEAMAPICALLRESULT_NONE = 0
};

// Steam API functions
extern "C" {

STEAM_API HSteamPipe GetHSteamPipe();
STEAM_API HSteamUser GetHSteamUser();
STEAM_API void* SteamClient();
STEAM_API void* SteamInternal_CreateInterface(const char* version);
STEAM_API bool SteamAPI_Init();
STEAM_API bool SteamAPI_InitSafe();
STEAM_API void SteamAPI_Shutdown();
STEAM_API void SteamAPI_RunCallbacks();
STEAM_API void SteamGameServer_Shutdown();
STEAM_API bool SteamGameServer_InitSafe();

// Global steam client pointer (for gameserver)
STEAM_API extern void* g_pSteamClientGameServer;

}
