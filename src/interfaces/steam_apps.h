#pragma once
#include "../../include/steam/steam_api_goldsrc.h"

class CSteamApps : public ISteamApps {
public:
    CSteamApps();
    virtual ~CSteamApps() = default;

    bool BIsAppInstalled(AppId_t appID) override;
    bool BIsGameInstalled() override;
    bool BIsSubscribed() override;
    bool BIsVACBanned() override;
    bool BIsCybercafe() override;
    bool BIsOffline() override;
    const char* GetAppName() override;
    int GetAppBuildId() override;
    const char* GetAppInstallDir(AppId_t appID, char* pchBuffer, int cchBuffer) override;
    bool BIsDLCInstalled(AppId_t appID) override;
    int GetDLCCount() override;
    bool BGetDLCDataByIndex(int iDLC, AppId_t* pAppID, bool* pbAvailable, char* pchName, int cchNameBufferSize) override;
    void InstallDLC(AppId_t appID) override;
    void UninstallDLC(AppId_t appID) override;
    bool IsTimedTrial() override;
    bool BIsFreeApp(AppId_t appID) override;
    bool BIsSubscribedApp(AppId_t appID) override;
    bool BIsSubscribedFromFamilySharing() override;
    bool BIsLowViolence() override;
    const char* GetCurrentGameLanguage() override;
    const char* GetAvailableGameLanguages() override;
    const char* GetBetaName() override;
    const char* GetLaunchCommandLine() override;
    const char* GetLaunchQueryParam(const char* pchKey) override;

    // Helper methods used by exports
    bool BIsDlcInstalled(AppId_t appID) { return BIsDLCInstalled(appID); }
    bool BIsTimedTrial() { return IsTimedTrial(); }
    bool BGetAppInstallDir(AppId_t appID, char* buf, int len) { return GetAppInstallDir(appID, buf, len) != nullptr; }
    CSteamID GetAppOwner() { return CSteamID(0x110000100001); }
    const char* GetCurrentBetaName() { return GetBetaName(); }

private:
    int m_nBuildID;
};