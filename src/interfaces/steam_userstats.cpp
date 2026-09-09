#include "steam_userstats.h"

CSteamUserStats::CSteamUserStats() {}

bool CSteamUserStats::RequestCurrentStats() { return true; }
bool CSteamUserStats::GetStat(const char* pchName, int* pData) { if (pData) *pData = 0; return true; }
bool CSteamUserStats::GetStat0(const char* pchName, float* pData) { if (pData) *pData = 0.0f; return true; }
bool CSteamUserStats::SetStat(const char* pchName, int nData) { return true; }
bool CSteamUserStats::SetStat0(const char* pchName, float fData) { return true; }
bool CSteamUserStats::UpdateAvgRateStat(const char* pchName, float flCountThisSession, double dSessionLength) { return true; }
bool CSteamUserStats::GetAchievement(const char* pchName, bool* pbAchieved) { if (pbAchieved) *pbAchieved = false; return true; }
bool CSteamUserStats::SetAchievement(const char* pchName) { return true; }
bool CSteamUserStats::ClearAchievement(const char* pchName) { return true; }
bool CSteamUserStats::StoreStats() { return true; }
int CSteamUserStats::GetAchievementIcon(const char* pchName) { return 0; }
const char* CSteamUserStats::GetAchievementDisplayAttribute(const char* pchName, const char* pchKey) { return ""; }
bool CSteamUserStats::IndicateAchievementProgress(const char* pchName, int nCurProgress, int nMaxProgress) { return true; }
bool CSteamUserStats::RequestGlobalStats(int nHistoryDays) { return true; }
bool CSteamUserStats::GetGlobalStat(const char* pchStatName, int64* pData) { if (pData) *pData = 0; return true; }
bool CSteamUserStats::GetGlobalStat0(const char* pchStatName, double* pData) { if (pData) *pData = 0.0; return true; }
int CSteamUserStats::GetGlobalStatHistory(const char* pchStatName, int64* pData, int cData) { return 0; }
int CSteamUserStats::GetGlobalStatHistory0(const char* pchStatName, double* pData, int cData) { return 0; }
bool CSteamUserStats::FindLeaderboard(const char* pchLeaderboardName) { return false; }
bool CSteamUserStats::FindOrCreateLeaderboard(const char* pchLeaderboardName, int eSortMethod, int eDisplayType) { return false; }
bool CSteamUserStats::GetLeaderboardEntryCount(int hSteamLeaderboard, int* pEntryCount) { if (pEntryCount) *pEntryCount = 0; return true; }
bool CSteamUserStats::GetLeaderboardSortMethod(int hSteamLeaderboard, int* pSortMethod) { if (pSortMethod) *pSortMethod = 0; return true; }
bool CSteamUserStats::GetLeaderboardDisplayType(int hSteamLeaderboard, int* pDisplayType) { if (pDisplayType) *pDisplayType = 0; return true; }
bool CSteamUserStats::DownloadLeaderboardEntries(int hSteamLeaderboard, int eLeaderboardDataRequest, int nRangeStart, int nRangeEnd) { return false; }
bool CSteamUserStats::GetDownloadedLeaderboardEntry(int hSteamLeaderboard, int index, int* pEntry, void* pDetails, int cDetailsMax) { return false; }
bool CSteamUserStats::AttachLeaderboardUGC(int hSteamLeaderboard, UGCHandle_t hUGC) { return false; }