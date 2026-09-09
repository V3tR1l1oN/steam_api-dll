#include "steam_utils.h"
#include <windows.h>
#include <time.h>

CSteamUtils::CSteamUtils() : m_nAppID(10), m_serverTime(0) {}

AppId_t CSteamUtils::GetAppID() { return m_nAppID; }
bool CSteamUtils::IsOverlayEnabled() { return true; }
bool CSteamUtils::BOverlayNeedsPresent() { return false; }
void CSteamUtils::SetOverlayNotificationPosition(const char* pchNotificationUILanguage) {}
bool CSteamUtils::IsSteamRunning() { return true; }
const char* CSteamUtils::GetSteamUILanguage() { return "english"; }
uint32 CSteamUtils::GetServerRealTime() { return (uint32)time(nullptr); }
int CSteamUtils::GetSecondsSinceAppActive() { return 0; }
int CSteamUtils::GetSecondsSinceComputerActive() { return 0; }
int CSteamUtils::GetConnectedUniverse() { return 1; }
int CSteamUtils::GetCurrentBatteryPower() { return 100; }
bool CSteamUtils::IsVRHeadsetStreamingEnabled() { return false; }
void CSteamUtils::SetVRHeadsetStreamingEnabled(bool bEnabled) {}
bool CSteamUtils::IsSteamInBigPictureMode() { return false; }
bool CSteamUtils::IsSteamChinaLauncher() { return false; }
bool CSteamUtils::IsSteamRunningOnSteamDeck() { return false; }
void CSteamUtils::StartVRDashboard() {}
bool CSteamUtils::IsVRDashboardVisible() { return false; }
bool CSteamUtils::BIsSteamInstalled() { return true; }
const char* CSteamUtils::GetSteamInstallPath() { return "."; }
int CSteamUtils::GetSteamBridgeVersion() { return 0; }
bool CSteamUtils::BIsBridgeRemotePlaying() { return false; }
bool CSteamUtils::BIsBridgeRunning() { return false; }