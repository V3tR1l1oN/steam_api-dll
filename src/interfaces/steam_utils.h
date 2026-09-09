#pragma once
#include "../../include/steam/steam_api_goldsrc.h"

class CSteamUtils : public ISteamUtils {
public:
    CSteamUtils();
    virtual ~CSteamUtils() = default;

    AppId_t GetAppID() override;
    bool IsOverlayEnabled() override;
    bool BOverlayNeedsPresent() override;
    void SetOverlayNotificationPosition(const char* pchNotificationUILanguage) override;
    bool IsSteamRunning() override;
    const char* GetSteamUILanguage() override;
    uint32 GetServerRealTime() override;
    int GetSecondsSinceAppActive() override;
    int GetSecondsSinceComputerActive() override;
    int GetConnectedUniverse() override;
    int GetCurrentBatteryPower() override;
    bool IsVRHeadsetStreamingEnabled() override;
    void SetVRHeadsetStreamingEnabled(bool bEnabled) override;
    bool IsSteamInBigPictureMode() override;
    bool IsSteamChinaLauncher() override;
    bool IsSteamRunningOnSteamDeck() override;
    void StartVRDashboard() override;
    bool IsVRDashboardVisible() override;
    bool BIsSteamInstalled() override;
    const char* GetSteamInstallPath() override;
    int GetSteamBridgeVersion() override;
    bool BIsBridgeRemotePlaying() override;
    bool BIsBridgeRunning() override;

    // Helper methods used by exports
    int GetBuildID() { return 8689; }
    bool IsSteamChina() { return false; }

private:
    AppId_t m_nAppID;
    uint32 m_serverTime;
};