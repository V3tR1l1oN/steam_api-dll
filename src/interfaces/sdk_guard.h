// sdk_guard.h — vtable-совместимые классы по SteamWorks SDK раскладке.
// Порядок виртуальных методов повторяет SDK-заголовки isteam*.h (source-sdk-2013).
#pragma once
#include "sdk_compat.h"

// ISteamFriends017 — 80 методов
class SdkSteamFriends {
public:
    virtual const char* GetPersonaName();
    virtual SteamAPICall_t SetPersonaName(const char*);
    virtual int GetPersonaState();
    virtual int GetFriendCount(int);
    virtual SdkSteamID GetFriendByIndex(int, int);
    virtual int GetFriendRelationship(SdkSteamID);
    virtual int GetFriendPersonaState(SdkSteamID);
    virtual const char* GetFriendPersonaName(SdkSteamID);
    virtual bool GetFriendGamePlayed(SdkSteamID, void*);
    virtual const char* GetFriendPersonaNameHistory(SdkSteamID, int);
    virtual int GetFriendSteamLevel(SdkSteamID);
    virtual const char* GetPlayerNickname(SdkSteamID);
    virtual int GetFriendsGroupCount();
    virtual short GetFriendsGroupIDByIndex(int);
    virtual const char* GetFriendsGroupName(short);
    virtual int GetFriendsGroupMembersCount(short);
    virtual void GetFriendsGroupMembersList(short, SdkSteamID*, int);
    virtual bool HasFriend(SdkSteamID, int);
    virtual int GetClanCount();
    virtual SdkSteamID GetClanByIndex(int);
    virtual const char* GetClanName(SdkSteamID);
    virtual const char* GetClanTag(SdkSteamID);
    virtual bool GetClanActivityCounts(SdkSteamID, int*, int*, int*);
    virtual SteamAPICall_t DownloadClanActivityCounts(SdkSteamID*, int);
    virtual int GetFriendCountFromSource(SdkSteamID);
    virtual SdkSteamID GetFriendFromSourceByIndex(SdkSteamID, int);
    virtual bool IsUserInSource(SdkSteamID, SdkSteamID);
    virtual void SetInGameVoiceSpeaking(SdkSteamID, bool);
    virtual void ActivateGameOverlay(const char*);
    virtual void ActivateGameOverlayToUser(const char*, SdkSteamID);
    virtual void ActivateGameOverlayToWebPage(const char*, int);
    virtual void ActivateGameOverlayToStore(AppId_t, int);
    virtual void SetPlayedWith(SdkSteamID);
    virtual void ActivateGameOverlayInviteDialog(SdkSteamID);
    virtual int GetSmallFriendAvatar(SdkSteamID);
    virtual int GetMediumFriendAvatar(SdkSteamID);
    virtual int GetLargeFriendAvatar(SdkSteamID);
    virtual bool RequestUserInformation(SdkSteamID, bool);
    virtual SteamAPICall_t RequestClanOfficerList(SdkSteamID);
    virtual SdkSteamID GetClanOwner(SdkSteamID);
    virtual int GetClanOfficerCount(SdkSteamID);
    virtual SdkSteamID GetClanOfficerByIndex(SdkSteamID, int);
    virtual unsigned int GetUserRestrictions();
    virtual bool SetRichPresence(const char*, const char*);
    virtual void ClearRichPresence();
    virtual const char* GetFriendRichPresence(SdkSteamID, const char*);
    virtual int GetFriendRichPresenceKeyCount(SdkSteamID);
    virtual const char* GetFriendRichPresenceKeyByIndex(SdkSteamID, int);
    virtual void RequestFriendRichPresence(SdkSteamID);
    virtual bool InviteUserToGame(SdkSteamID, const char*);
    virtual int GetCoplayFriendCount();
    virtual SdkSteamID GetCoplayFriend(int);
    virtual int GetFriendCoplayTime(SdkSteamID);
    virtual AppId_t GetFriendCoplayGame(SdkSteamID);
    virtual SteamAPICall_t JoinClanChatRoom(SdkSteamID);
    virtual bool LeaveClanChatRoom(SdkSteamID);
    virtual int GetClanChatMemberCount(SdkSteamID);
    virtual SdkSteamID GetChatMemberByIndex(SdkSteamID, int);
    virtual bool SendClanChatMessage(SdkSteamID, const char*);
    virtual int GetClanChatMessage(SdkSteamID, int, void*, int, int*, SdkSteamID*);
    virtual bool IsClanChatAdmin(SdkSteamID, SdkSteamID);
    virtual bool IsClanChatWindowOpenInSteam(SdkSteamID);
    virtual bool OpenClanChatWindowInSteam(SdkSteamID);
    virtual bool CloseClanChatWindowInSteam(SdkSteamID);
    virtual bool SetListenForFriendsMessages(bool);
    virtual bool ReplyToFriendMessage(SdkSteamID, const char*);
    virtual int GetFriendMessage(SdkSteamID, int, void*, int, int*);
    virtual SteamAPICall_t GetFollowerCount(SdkSteamID);
    virtual SteamAPICall_t IsFollowing(SdkSteamID);
    virtual SteamAPICall_t EnumerateFollowingList(unsigned int);
    virtual bool IsClanPublic(SdkSteamID);
    virtual bool IsClanOfficialGameGroup(SdkSteamID);
    virtual int GetNumChatsWithUnreadPriorityMessages();
    virtual void ActivateGameOverlayRemotePlayTogetherInviteDialog(SdkSteamID);
    virtual bool RegisterProtocolInOverlayBrowser(const char*);
    virtual void ActivateGameOverlayInviteDialogConnectString(const char*);
    virtual SteamAPICall_t RequestEquippedProfileItems(SdkSteamID);
    virtual bool BHasEquippedProfileItem(SdkSteamID, int);
    virtual const char* GetProfileItemPropertyString(SdkSteamID, int, int);
    virtual unsigned int GetProfileItemPropertyUint(SdkSteamID, int, int);
};

// STEAMAPPS_INTERFACE_VERSION008 — 30 методов
class SdkSteamApps {
public:
    virtual bool BIsSubscribed();
    virtual bool BIsLowViolence();
    virtual bool BIsCybercafe();
    virtual bool BIsVACBanned();
    virtual const char* GetCurrentGameLanguage();
    virtual const char* GetAvailableGameLanguages();
    virtual bool BIsSubscribedApp(AppId_t);
    virtual bool BIsDlcInstalled(AppId_t);
    virtual unsigned int GetEarliestPurchaseUnixTime(AppId_t);
    virtual bool BIsSubscribedFromFreeWeekend();
    virtual int GetDLCCount();
    virtual bool BGetDLCDataByIndex(int, AppId_t*, bool*, char*, int);
    virtual void InstallDLC(AppId_t);
    virtual void UninstallDLC(AppId_t);
    virtual void RequestAppProofOfPurchaseKey(AppId_t);
    virtual bool GetCurrentBetaName(char*, int);
    virtual bool MarkContentCorrupt(bool);
    virtual unsigned int GetInstalledDepots(AppId_t, unsigned int*, unsigned int);
    virtual unsigned int GetAppInstallDir(AppId_t, char*, unsigned int);
    virtual bool BIsAppInstalled(AppId_t);
    virtual SdkSteamID GetAppOwner();
    virtual const char* GetLaunchQueryParam(const char*);
    virtual bool GetDlcDownloadProgress(AppId_t, unsigned long long*, unsigned long long*);
    virtual int GetAppBuildId();
    virtual void RequestAllProofOfPurchaseKeys();
    virtual SteamAPICall_t GetFileDetails(const char*);
    virtual int GetLaunchCommandLine(char*, int);
    virtual bool BIsSubscribedFromFamilySharing();
    virtual bool BIsTimedTrial(unsigned int*, unsigned int*);
    virtual bool SetDlcContext(AppId_t);
};

// ISteamUserStats012 — 45 методов
class SdkSteamUserStats {
public:
    virtual bool RequestCurrentStats();
    virtual bool GetStatInt(const char*, int*);
    virtual bool GetStatFloat(const char*, float*);
    virtual bool SetStatInt(const char*, int);
    virtual bool SetStatFloat(const char*, float);
    virtual bool UpdateAvgRateStat(const char*, float, double);
    virtual bool GetAchievement(const char*, bool*);
    virtual bool SetAchievement(const char*);
    virtual bool ClearAchievement(const char*);
    virtual bool GetAchievementAndUnlockTime(const char*, bool*, unsigned int*);
    virtual bool StoreStats();
    virtual int GetAchievementIcon(const char*);
    virtual const char* GetAchievementDisplayAttribute(const char*, const char*);
    virtual bool IndicateAchievementProgress(const char*, unsigned int, unsigned int);
    virtual unsigned int GetNumAchievements();
    virtual const char* GetAchievementName(unsigned int);
    virtual SteamAPICall_t RequestUserStats(SdkSteamID);
    virtual bool GetUserStatInt(SdkSteamID, const char*, int*);
    virtual bool GetUserStatFloat(SdkSteamID, const char*, float*);
    virtual bool GetUserAchievement(SdkSteamID, const char*, bool*);
    virtual bool GetUserAchievementAndUnlockTime(SdkSteamID, const char*, bool*, unsigned int*);
    virtual bool ResetAllStats(bool);
    virtual SteamAPICall_t FindOrCreateLeaderboard(const char*, int, int);
    virtual SteamAPICall_t FindLeaderboard(const char*);
    virtual const char* GetLeaderboardName(unsigned long long);
    virtual int GetLeaderboardEntryCount(unsigned long long);
    virtual int GetLeaderboardSortMethod(unsigned long long);
    virtual int GetLeaderboardDisplayType(unsigned long long);
    virtual SteamAPICall_t DownloadLeaderboardEntries(unsigned long long, int, int, int);
    virtual SteamAPICall_t DownloadLeaderboardEntriesForUsers(unsigned long long, SdkSteamID*, int);
    virtual bool GetDownloadedLeaderboardEntry(unsigned long long, int, void*, int*, int);
    virtual SteamAPICall_t UploadLeaderboardScore(unsigned long long, int, int, const int*, int);
    virtual SteamAPICall_t AttachLeaderboardUGC(unsigned long long, unsigned long long);
    virtual SteamAPICall_t GetNumberOfCurrentPlayers();
    virtual SteamAPICall_t RequestGlobalAchievementPercentages();
    virtual int GetMostAchievedAchievementInfo(char*, unsigned int, float*, bool*);
    virtual int GetNextMostAchievedAchievementInfo(int, char*, unsigned int, float*, bool*);
    virtual bool GetAchievementAchievedPercent(const char*, float*);
    virtual SteamAPICall_t RequestGlobalStats(int);
    virtual bool GetGlobalStatInt(const char*, long long*);
    virtual bool GetGlobalStatFloat(const char*, double*);
    virtual int GetGlobalStatHistoryInt(const char*, long long*, unsigned int);
    virtual int GetGlobalStatHistoryFloat(const char*, double*, unsigned int);
    virtual bool GetAchievementProgressLimitsInt(const char*, int*, int*);
    virtual bool GetAchievementProgressLimitsFloat(const char*, float*, float*);
};

// ISteamNetworking006 — 22 метода
class SdkSteamNetworking {
public:
    virtual bool SendP2PPacket(SdkSteamID, const void*, unsigned int, int, int);
    virtual bool IsP2PPacketAvailable(unsigned int*, int);
    virtual bool ReadP2PPacket(void*, unsigned int, unsigned int*, SdkSteamID*, int);
    virtual bool AcceptP2PSessionWithUser(SdkSteamID);
    virtual bool CloseP2PSessionWithUser(SdkSteamID);
    virtual bool CloseP2PChannelWithUser(SdkSteamID, int);
    virtual bool GetP2PSessionState(SdkSteamID, void*);
    virtual bool AllowP2PPacketRelay(bool);
    virtual int CreateListenSocket(int, unsigned int, unsigned short, bool);
    virtual int CreateP2PConnectionSocket(SdkSteamID, int, int, bool);
    virtual int CreateConnectionSocket(unsigned int, unsigned short, int);
    virtual bool DestroySocket(int, bool);
    virtual bool DestroyListenSocket(int, bool);
    virtual bool SendDataOnSocket(int, void*, unsigned int, bool);
    virtual bool IsDataAvailableOnSocket(int, unsigned int*);
    virtual bool RetrieveDataFromSocket(int, void*, unsigned int, unsigned int*);
    virtual bool IsDataAvailable(int, unsigned int*, int*);
    virtual bool RetrieveData(int, void*, unsigned int, unsigned int*, int*);
    virtual bool GetSocketInfo(int, SdkSteamID*, int*, unsigned int*, unsigned short*);
    virtual bool GetListenSocketInfo(int, unsigned int*, unsigned short*);
    virtual int GetSocketConnectionType(int);
    virtual int GetMaxPacketSize(int);
};

// ISteamMatchmaking009 — 93 метода (первые 38 реализованы, 39-93 нужны как no-op виртуалы)
class SdkSteamMatchmaking {
public:
    virtual int GetFavoriteGameCount();
    virtual bool GetFavoriteGame(int, AppId_t*, unsigned int*, unsigned short*, unsigned short*, unsigned int*, unsigned int*);
    virtual int AddFavoriteGame(AppId_t, unsigned int, unsigned short, unsigned short, unsigned int, unsigned int);
    virtual bool RemoveFavoriteGame(AppId_t, unsigned int, unsigned short, unsigned short, unsigned int);
    virtual SteamAPICall_t RequestLobbyList();
    virtual void AddRequestLobbyListStringFilter(const char*, const char*, int);
    virtual void AddRequestLobbyListNumericalFilter(const char*, int, int);
    virtual void AddRequestLobbyListNearValueFilter(const char*, int);
    virtual void AddRequestLobbyListFilterSlotsAvailable(int);
    virtual void AddRequestLobbyListDistanceFilter(int);
    virtual void AddRequestLobbyListResultCountFilter(int);
    virtual void AddRequestLobbyListCompatibleMembersFilter(SdkSteamID);
    virtual SdkSteamID GetLobbyByIndex(int);
    virtual SteamAPICall_t CreateLobby(int, int);
    virtual SteamAPICall_t JoinLobby(SdkSteamID);
    virtual void LeaveLobby(SdkSteamID);
    virtual bool InviteUserToLobby(SdkSteamID, SdkSteamID);
    virtual int GetNumLobbyMembers(SdkSteamID);
    virtual SdkSteamID GetLobbyMemberByIndex(SdkSteamID, int);
    virtual const char* GetLobbyData(SdkSteamID, const char*);
    virtual bool SetLobbyData(SdkSteamID, const char*, const char*);
    virtual int GetLobbyDataCount(SdkSteamID);
    virtual bool GetLobbyDataByIndex(SdkSteamID, int, char*, int, char*, int);
    virtual bool DeleteLobbyData(SdkSteamID, const char*);
    virtual const char* GetLobbyMemberData(SdkSteamID, SdkSteamID, const char*);
    virtual void SetLobbyMemberData(SdkSteamID, const char*, const char*);
    virtual bool SendLobbyChatMsg(SdkSteamID, const void*, int);
    virtual int GetLobbyChatEntry(SdkSteamID, int, SdkSteamID*, void*, int, int*);
    virtual bool RequestLobbyData(SdkSteamID);
    virtual void SetLobbyGameServer(SdkSteamID, unsigned int, unsigned short, SdkSteamID);
    virtual bool GetLobbyGameServer(SdkSteamID, unsigned int*, unsigned short*, SdkSteamID*);
    virtual bool SetLobbyMemberLimit(SdkSteamID, int);
    virtual int GetLobbyMemberLimit(SdkSteamID);
    virtual bool SetLobbyType(SdkSteamID, int);
    virtual bool SetLobbyJoinable(SdkSteamID, bool);
    virtual SdkSteamID GetLobbyOwner(SdkSteamID);
    virtual bool SetLobbyOwner(SdkSteamID, SdkSteamID);
    virtual bool SetLinkedLobby(SdkSteamID, SdkSteamID);
    // Слоты 39-93: PSN invite, server-list response callbacks, GameSearch, beacons.
    // Движок CS 1.6 их не вызывает; объявления опущены — vtable кончается на 39 слоте.
};
