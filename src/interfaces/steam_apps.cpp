#include "steam_apps.h"
#include <cstring>

CSteamApps::CSteamApps() : m_nBuildID(8689) {}

bool CSteamApps::BIsAppInstalled(AppId_t appID) { return appID == 10; }
bool CSteamApps::BIsGameInstalled() { return true; }
bool CSteamApps::BIsSubscribed() { return true; }
bool CSteamApps::BIsVACBanned() { return false; }
bool CSteamApps::BIsCybercafe() { return false; }
bool CSteamApps::BIsOffline() { return false; }
const char* CSteamApps::GetAppName() { return "Counter-Strike"; }
int CSteamApps::GetAppBuildId() { return m_nBuildID; }
const char* CSteamApps::GetAppInstallDir(AppId_t appID, char* pchBuffer, int cchBuffer) {
    if (cchBuffer > 0) { strcpy_s(pchBuffer, cchBuffer, "."); }
    return pchBuffer;
}
bool CSteamApps::BIsDLCInstalled(AppId_t appID) { return false; }
int CSteamApps::GetDLCCount() { return 0; }
bool CSteamApps::BGetDLCDataByIndex(int iDLC, AppId_t* pAppID, bool* pbAvailable, char* pchName, int cchNameBufferSize) { return false; }
void CSteamApps::InstallDLC(AppId_t appID) {}
void CSteamApps::UninstallDLC(AppId_t appID) {}
bool CSteamApps::IsTimedTrial() { return false; }
bool CSteamApps::BIsFreeApp(AppId_t appID) { return false; }
bool CSteamApps::BIsSubscribedApp(AppId_t appID) { return true; }
bool CSteamApps::BIsSubscribedFromFamilySharing() { return false; }
bool CSteamApps::BIsLowViolence() { return false; }
const char* CSteamApps::GetCurrentGameLanguage() { return "english"; }
const char* CSteamApps::GetAvailableGameLanguages() { return "english"; }
const char* CSteamApps::GetBetaName() { return ""; }
const char* CSteamApps::GetLaunchCommandLine() { return ""; }
const char* CSteamApps::GetLaunchQueryParam(const char* pchKey) { return ""; }