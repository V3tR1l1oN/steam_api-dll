#pragma once
#include "../../include/steam/steam_api_goldsrc.h"
#include <map>
#include <string>

class CSteamUserStats : public ISteamUserStats {
public:
    CSteamUserStats();
    virtual ~CSteamUserStats() = default;

    bool RequestCurrentStats() override;
    bool GetStat(const char* pchName, int* pData) override;
    bool GetStat0(const char* pchName, float* pData) override;
    bool SetStat(const char* pchName, int nData) override;
    bool SetStat0(const char* pchName, float fData) override;
    bool UpdateAvgRateStat(const char* pchName, float flCountThisSession, double dSessionLength) override;
    bool GetAchievement(const char* pchName, bool* pbAchieved) override;
    bool SetAchievement(const char* pchName) override;
    bool ClearAchievement(const char* pchName) override;
    bool StoreStats() override;
    int GetAchievementIcon(const char* pchName) override;
    const char* GetAchievementDisplayAttribute(const char* pchName, const char* pchKey) override;
    bool IndicateAchievementProgress(const char* pchName, int nCurProgress, int nMaxProgress) override;
    bool RequestGlobalStats(int nHistoryDays) override;
    bool GetGlobalStat(const char* pchStatName, int64* pData) override;
    bool GetGlobalStat0(const char* pchStatName, double* pData) override;
    int GetGlobalStatHistory(const char* pchStatName, int64* pData, int cData) override;
    int GetGlobalStatHistory0(const char* pchStatName, double* pData, int cData) override;
    bool FindLeaderboard(const char* pchLeaderboardName) override;
    bool FindOrCreateLeaderboard(const char* pchLeaderboardName, int eSortMethod, int eDisplayType) override;
    bool GetLeaderboardEntryCount(int hSteamLeaderboard, int* pEntryCount) override;
    bool GetLeaderboardSortMethod(int hSteamLeaderboard, int* pSortMethod) override;
    bool GetLeaderboardDisplayType(int hSteamLeaderboard, int* pDisplayType) override;
    bool DownloadLeaderboardEntries(int hSteamLeaderboard, int eLeaderboardDataRequest, int nRangeStart, int nRangeEnd) override;
    bool GetDownloadedLeaderboardEntry(int hSteamLeaderboard, int index, int* pEntry, void* pDetails, int cDetailsMax) override;
    bool AttachLeaderboardUGC(int hSteamLeaderboard, UGCHandle_t hUGC) override;
};