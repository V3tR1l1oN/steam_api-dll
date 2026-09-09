// SdkSteamClient — ISteamClient021 по раскладке isteamclient.h (36 методов).
// Оффлайн-реализация: CreateSteamPipe/CreateLocalUser возвращают валидные хэндлы,
// GetISteamXXX возвращают наши vtable-совместимые объекты.
#pragma once
#include "sdk_guard.h"

class SdkSteamClient {
public:
    // 1
    virtual int CreateSteamPipe() { return 1; }
    // 2
    virtual bool BReleaseSteamPipe(int) { return true; }
    // 3
    virtual int ConnectToGlobalUser(int) { return 1; }
    // 4
    virtual int CreateLocalUser(int* phSteamPipe, int eAccountType) { if (phSteamPipe) *phSteamPipe = 1; return 1; }
    // 5
    virtual void ReleaseUser(int, int) {}
    // 6
    virtual SdkSteamUser* GetISteamUser(int, int, const char*) { static SdkSteamUser u; return &u; }
    // 7
    virtual void* GetISteamGameServer(int, int, const char*) { return nullptr; }
    // 8
    virtual void SetLocalIPBinding(unsigned int, unsigned short) {}
    // 9
    virtual SdkSteamFriends* GetISteamFriends(int, int, const char*) { static SdkSteamFriends f; return &f; }
    // 10
    virtual SdkSteamUtils* GetISteamUtils(int, const char*) { static SdkSteamUtils u; return &u; }
    // 11
    virtual SdkSteamMatchmaking* GetISteamMatchmaking(int, int, const char*) { static SdkSteamMatchmaking m; return &m; }
    // 12
    virtual void* GetISteamMatchmakingServers(int, int, const char*) { return nullptr; }
    // 13
    virtual void* GetISteamGenericInterface(int, int, const char*) { return nullptr; }
    // 14
    virtual SdkSteamUserStats* GetISteamUserStats(int, int, const char*) { static SdkSteamUserStats s; return &s; }
    // 15
    virtual void* GetISteamGameServerStats(int, int, const char*) { return nullptr; }
    // 16
    virtual SdkSteamApps* GetISteamApps(int, int, const char*) { static SdkSteamApps a; return &a; }
    // 17
    virtual SdkSteamNetworking* GetISteamNetworking(int, int, const char*) { static SdkSteamNetworking n; return &n; }
    // 18
    virtual void* GetISteamRemoteStorage(int, int, const char*) { return nullptr; }
    // 19
    virtual void* GetISteamScreenshots(int, int, const char*) { return nullptr; }
    // 20
    virtual void* GetISteamGameSearch(int, int, const char*) { return nullptr; }
    // 21
    virtual unsigned int GetIPCCallCount() { return 0; }
    // 22
    virtual void SetWarningMessageHook(void*) {}
    // 23
    virtual bool BShutdownIfAllPipesClosed() { return false; }
    // 24
    virtual void* GetISteamHTTP(int, int, const char*) { return nullptr; }
    // 25
    virtual void* DEPRECATED_GetISteamUnifiedMessages(int, int, const char*) { return nullptr; }
    // 26
    virtual void* GetISteamController(int, int, const char*) { return nullptr; }
    // 26
    virtual void* GetISteamUGC(int, int, const char*) { return nullptr; }
    // 27
    virtual void* GetISteamAppList(int, int, const char*) { return nullptr; }
    // 28
    virtual void* GetISteamMusic(int, int, const char*) { return nullptr; }
    // 29
    virtual void* GetISteamMusicRemote(int, int, const char*) { return nullptr; }
    // 30
    virtual void* GetISteamHTMLSurface(int, int, const char*) { return nullptr; }
    // 31
    virtual void* GetISteamInventory(int, int, const char*) { return nullptr; }
    // 32
    virtual void* GetISteamVideo(int, int, const char*) { return nullptr; }
    // 32b
    virtual void DEPRECATED_Set_SteamAPI_CPostAPIResultInProcess() {}
    // 32c
    virtual void DEPRECATED_Remove_SteamAPI_CPostAPIResultInProcess() {}
    // 32d
    virtual void Set_SteamAPI_CCheckCallbackRegisteredInProcess() {}
    // 33
    virtual void* GetISteamParentalSettings(int, int, const char*) { return nullptr; }
    // 34
    virtual void* GetISteamInput(int, int, const char*) { return nullptr; }
    // 35
    virtual void* GetISteamParties(int, int, const char*) { return nullptr; }
    // 36
    virtual void* GetISteamRemotePlay(int, int, const char*) { return nullptr; }
    // 37+
    virtual void DestroyAllInterfaces() {}
};
