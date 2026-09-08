#pragma once
#include <windows.h>
#include <string>

typedef unsigned int AppId_t;
typedef int SNetSocket_t;
typedef int SNetListenSocket_t;
typedef unsigned int ScreenshotHandle;
typedef unsigned int HTTPRequestHandle;
typedef unsigned int ControllerHandle_t;
typedef unsigned long long SteamAPICall_t;
typedef unsigned long long uint64;
typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;
typedef long long int64;
typedef int int32;
typedef signed char int8;
typedef signed short int16;
typedef unsigned long long UGCHandle_t;
typedef unsigned long long UGCQueryHandle_t;
typedef unsigned long long UGCUpdateHandle_t;
typedef int HSteamUser;
typedef int HSteamPipe;
typedef int MeridithH;

struct CSteamID {
    uint64 m_steamid;
    CSteamID() : m_steamid(0) {}
    CSteamID(uint64 s) : m_steamid(s) {}
    operator uint64() const { return m_steamid; }
    uint32 GetAccountID() const { return m_steamid & 0xFFFFFFFF; }
    int GetAccountType() const { return (m_steamid >> 20) & 0xF; }
};

struct FriendGameInfo_t {
    uint64 m_steamIDGameServer;
    uint32 m_unGameIP;
    uint16 m_usGamePort;
    uint16 m_usQueryPort;
    uint32 m_uFlags;
};

struct CGameID {
    uint64 m_ulGameID;
    CGameID() : m_ulGameID(0) {}
    CGameID(uint64 id) : m_ulGameID(id) {}
    operator uint64() const { return m_ulGameID; }
};

struct SteamPlayerInfo_t {
    char m_playerName[64];
    uint64 m_steamID;
};

class ISteamUser {
public:
    virtual HSteamUser GetHSteamUser() = 0;
    virtual bool BLoggedOn() = 0;
    virtual CSteamID GetSteamID() = 0;
    virtual bool BIsSameUser(HSteamUser hUser) = 0;
    virtual int InitiateGameConnection(void* pAuthBlob, int cbMaxAuthBlob, CSteamID steamID, uint32 unGameServerIP, uint16 usGameServerPort, bool bSecure) = 0;
    virtual void TerminateGameConnection(uint32 unGameServerIP, uint16 usGameServerPort) = 0;
    virtual void TerminateGameConnection2(uint32 unGameServerIP, uint16 usGameServerPort) = 0;
    virtual void TrackAppUsageEvent(CGameID gameID, int eAppUsageEvent, const char* pchExtraInfo = "") = 0;
    virtual bool GetUserDataFolder(char* pchBuffer, int cubBuffer) = 0;
    virtual void StartVoiceRecording() = 0;
    virtual void StopVoiceRecording() = 0;
    virtual int GetVoiceAvailable(bool bCompressed) = 0;
    virtual int GetVoiceNeeded(bool bCompressed) = 0;
    virtual int GetVoice(char* pDestBuffer, int cbDestBufferSize, bool bCompressed) = 0;
    virtual int GetVoiceOptimalSampleRate() = 0;
    virtual int GetAuthSessionTicket(void* pTicket, int cbMaxTicket, uint32* pcbTicket) = 0;
    virtual void CancelAuthTicket(uint32 hAuthTicket) = 0;
    virtual int BeginAuthSession(const void* pAuthTicket, int cbAuthTicket, CSteamID steamID) = 0;
    virtual void EndAuthSession(CSteamID steamID) = 0;
    virtual bool IsVACBanned(int nVACBanIndex) = 0;
    virtual void RequireShowVACBannedScreen(int nVACBanIndex) = 0;
    virtual int GetGameBadgeLevel(int nSeries) = 0;
    virtual void SetDurationControlOnlineState(int nNewState) = 0;
    virtual bool BIsDurationControlEnabled() = 0;
    virtual int GetSteamGuardDetails() = 0;
    virtual bool BIsTwoFactorEnabled() = 0;
    virtual int GetMarketEligibility() = 0;
    virtual bool BIsPhoneIdentifying() = 0;
    virtual bool BIsPhoneRequireVerification() = 0;
    virtual bool BIsPhoneVerified() = 0;
    virtual bool BIsAppOwned(int nAppID) = 0;
};

class ISteamFriends {
public:
    virtual const char* GetPersonaName() = 0;
    virtual bool SetPersonaName(const char* pchPersonaName) = 0;
    virtual int GetPersonaState() = 0;
    virtual CSteamID GetSteamFriends() = 0;
    virtual int GetFriendCount(int iFriendFlags) = 0;
    virtual CSteamID GetFriendByIndex(int iFriend, int iFriendFlags) = 0;
    virtual CSteamID GetFriendSteamID(int iFriend) = 0;
    virtual int GetFriendRelationship(CSteamID steamID) = 0;
    virtual const char* GetFriendPersonaName(CSteamID steamID) = 0;
    virtual int GetFriendPersonaState(CSteamID steamID) = 0;
    virtual bool GetFriendGamePlayed(CSteamID steamID, FriendGameInfo_t* pGamePlayInfo) = 0;
    virtual const char* GetFriendGameName(CSteamID steamID) = 0;
    virtual int GetFriendRegions(CSteamID steamID) = 0;
    virtual int GetClanCount() = 0;
    virtual CSteamID GetClanByIndex(int iClan) = 0;
    virtual const char* GetClanName(CSteamID steamID) = 0;
    virtual const char* GetClanTag(CSteamID steamID) = 0;
    virtual bool GetClanActivityCounts(CSteamID steamID, int* pnOnline, int* pnInGame, int* pnChatting) = 0;
    virtual int DownloadClanActivityCounts(CSteamID* psteamIDClans, int cClans) = 0;
    virtual int GetFriendsGroupCount() = 0;
    virtual int GetFriendsGroupIDByIndex(int iFG) = 0;
    virtual const char* GetFriendsGroupName(int FriendsGroupID) = 0;
    virtual int GetFriendsGroupMembersCount(int FriendsGroupID) = 0;
    virtual void GetFriendsGroupMembersList(int FriendsGroupID, CSteamID* pOutSteamIDMembers, int cMembersArraySize) = 0;
    virtual bool HasFriend(CSteamID steamID, int iFriendFlags) = 0;
    virtual int GetClanOfficerCount(CSteamID steamID) = 0;
    virtual CSteamID GetClanOfficerByIndex(CSteamID steamID, int iOfficer) = 0;
    virtual void RequestClanOfficerList(CSteamID steamID) = 0;
    virtual void SetRichPresence(const char* pchKey, const char* pchValue) = 0;
    virtual void ClearRichPresence() = 0;
    virtual const char* GetFriendRichPresence(const char* pchKey) = 0;
    virtual int GetFriendRichPresenceKeyCount(CSteamID steamID) = 0;
    virtual const char* GetFriendRichPresenceKeyByIndex(CSteamID steamID, int iKey) = 0;
    virtual void RequestFriendRichPresence(CSteamID steamID) = 0;
    virtual bool InviteUserToClan(CSteamID steamIDClan, CSteamID steamIDInvitee) = 0;
    virtual bool InviteUserToGame(CSteamID steamID, const char* pchConnectionString) = 0;
    virtual int GetFollowerCount(CSteamID steamID) = 0;
    virtual bool IsFollowing(CSteamID steamID) = 0;
    virtual int GetFollowingCount() = 0;
    virtual CSteamID GetFollowingByIndex(int iIndex) = 0;
};

class ISteamUtils {
public:
    virtual AppId_t GetAppID() = 0;
    virtual bool IsOverlayEnabled() = 0;
    virtual bool BOverlayNeedsPresent() = 0;
    virtual void SetOverlayNotificationPosition(const char* pchNotificationUILanguage) = 0;
    virtual bool IsSteamRunning() = 0;
    virtual const char* GetSteamUILanguage() = 0;
    virtual uint32 GetServerRealTime() = 0;
    virtual int GetSecondsSinceAppActive() = 0;
    virtual int GetSecondsSinceComputerActive() = 0;
    virtual int GetConnectedUniverse() = 0;
    virtual int GetCurrentBatteryPower() = 0;
    virtual bool IsVRHeadsetStreamingEnabled() = 0;
    virtual void SetVRHeadsetStreamingEnabled(bool bEnabled) = 0;
    virtual bool IsSteamInBigPictureMode() = 0;
    virtual bool IsSteamChinaLauncher() = 0;
    virtual bool IsSteamRunningOnSteamDeck() = 0;
    virtual void StartVRDashboard() = 0;
    virtual bool IsVRDashboardVisible() = 0;
    virtual bool BIsSteamInstalled() = 0;
    virtual const char* GetSteamInstallPath() = 0;
    virtual int GetSteamBridgeVersion() = 0;
    virtual bool BIsBridgeRemotePlaying() = 0;
    virtual bool BIsBridgeRunning() = 0;
};

class ISteamApps {
public:
    virtual bool BIsAppInstalled(AppId_t appID) = 0;
    virtual bool BIsGameInstalled() = 0;
    virtual bool BIsSubscribed() = 0;
    virtual bool BIsVACBanned() = 0;
    virtual bool BIsCybercafe() = 0;
    virtual bool BIsOffline() = 0;
    virtual const char* GetAppName() = 0;
    virtual int GetAppBuildId() = 0;
    virtual const char* GetAppInstallDir(AppId_t appID, char* pchBuffer, int cchBuffer) = 0;
    virtual bool BIsDLCInstalled(AppId_t appID) = 0;
    virtual int GetDLCCount() = 0;
    virtual bool BGetDLCDataByIndex(int iDLC, AppId_t* pAppID, bool* pbAvailable, char* pchName, int cchNameBufferSize) = 0;
    virtual void InstallDLC(AppId_t appID) = 0;
    virtual void UninstallDLC(AppId_t appID) = 0;
    virtual bool IsTimedTrial() = 0;
    virtual bool BIsFreeApp(AppId_t appID) = 0;
    virtual bool BIsSubscribedApp(AppId_t appID) = 0;
    virtual bool BIsSubscribedFromFamilySharing() = 0;
    virtual bool BIsLowViolence() = 0;
    virtual const char* GetCurrentGameLanguage() = 0;
    virtual const char* GetAvailableGameLanguages() = 0;
    virtual const char* GetBetaName() = 0;
    virtual const char* GetLaunchCommandLine() = 0;
    virtual const char* GetLaunchQueryParam(const char* pchKey) = 0;
};

class ISteamNetworking {
public:
    virtual bool SendP2PPacket(CSteamID steamIDRemote, const void* pData, uint32 cubData, int nSendFlags, int nChannel) = 0;
    virtual bool IsP2PPacketAvailable(uint32* pcubDataSize, int nChannel) = 0;
    virtual bool ReadP2PPacket(void* pDest, uint32 cubDest, uint32* pcubMsgSize, CSteamID* psteamIDRemote, int nChannel) = 0;
    virtual bool AcceptP2PSessionWithUser(CSteamID steamIDRemote) = 0;
    virtual bool CloseP2PSessionWithUser(CSteamID steamIDRemote) = 0;
    virtual bool CloseP2PChannelWithUser(CSteamID steamIDRemote, int nChannel) = 0;
    virtual SNetListenSocket_t CreateP2PListenSocket(int nSteamConnectPort, int nOptions, int nUserData) = 0;
    virtual SNetSocket_t CreateP2PConnectionSocket(CSteamID steamIDTarget, int nSteamPort, int nOptions, int nUserData) = 0;
    virtual SNetSocket_t ConnectP2P(const char* pszSteamID, int nSteamConnectPort, int nOptions, int nUserData) = 0;
    virtual bool DestroySocket(SNetSocket_t hSocket, bool bNotifyRemote) = 0;
    virtual bool DestroyListenSocket(SNetListenSocket_t hSocket, bool bNotifyRemote) = 0;
    virtual bool SendDataOnSocket(SNetSocket_t hSocket, const void* pData, uint32 cubData, bool bReliable) = 0;
    virtual bool IsDataAvailableOnSocket(SNetSocket_t hSocket, uint32* pcubDataSize) = 0;
    virtual bool RetrieveDataFromSocket(SNetSocket_t hSocket, void* pDest, uint32 cubDest, uint32* pcubMsgSize) = 0;
    virtual bool IsListening(SNetListenSocket_t hSocket) = 0;
    virtual SNetSocket_t GetP2PSessionConnectionInfo(CSteamID steamIDRemote, int* pi_snaux, int* pi_rfcong, int* pi_sdsend, uint64* pulTimeout) = 0;
    virtual int GetP2PSessionState(CSteamID steamIDRemote, void* pConnectionState) = 0;
    virtual bool SetP2PSessionSettings(int nChannel, bool bAllowRelay) = 0;
    virtual bool SetP2PSessionDefaultTimeout(int nTimeout) = 0;
    virtual void SetAlwaysRelay(bool bAlwaysRelay) = 0;
    virtual bool BAllowP2PPacketRelay(bool bAllow) = 0;
};

class ISteamMatchmaking {
public:
    virtual int GetFavoriteGameCount() = 0;
    virtual bool GetFavoriteGame(int iGame, AppId_t* pnAppID, uint32* pnIP, uint16* pnConnPort, uint16* pnQueryPort, uint32* punFlags, uint32* pRTime32LastPlayedOnServer) = 0;
    virtual int AddFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer) = 0;
    virtual bool RemoveFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags) = 0;
    virtual int GetServerCount(int iFirst, int iLast) = 0;
    virtual bool GetServerDetails(int iServer, uint32* pnIP, uint16* pnQueryPort, uint16* pnConnPort, uint8* pchName) = 0;
    virtual int AddServerToFavorites(uint32 nIP, uint16 nQueryPort, uint16 nConnPort, uint32 unAccountFlags) = 0;
    virtual bool RemoveServerFromFavorites(uint32 nIP, uint16 nQueryPort) = 0;
    virtual int PingServer(uint32 unIP, uint16 usPort, uint32* pFullServerProgress) = 0;
    virtual int ServerListRequest(char* pchServerListURL) = 0;
    virtual bool GetServerPingToServerRank(int a, int b, int c) = 0;
    virtual int CreateQueryPortServer(int a, bool b, const char* c) = 0;
    virtual void RequestLobbyList() = 0;
    virtual int GetLobbyListRequestResults(char* pchServerListURL) = 0;
    virtual void AddRequestLobbyListStringFilter(const char* pchKey, const char* pchValue, int nValueType) = 0;
    virtual void AddRequestLobbyListNumericalFilter(const char* pchKey, int nValue, int nComparisonType) = 0;
    virtual void AddRequestLobbyListNearValueFilter(const char* pchKey, int nValue) = 0;
    virtual CSteamID GetLobbyByIndex(int iLobby) = 0;
    virtual void CreateLobby(int bPrivate) = 0;
    virtual void SetLobbyData(CSteamID steamIDLobby, const char* pchKey, const char* pchValue) = 0;
    virtual int GetLobbyDataCount(CSteamID steamIDLobby) = 0;
    virtual bool GetLobbyDataByIndex(CSteamID steamIDLobby, int iLobbyData, char* pchKey, int cchKeyBufferSize, char* pchValue, int cchValueBufferSize) = 0;
    virtual void SetLobbyData64(CSteamID steamIDLobby, const char* pchKey, int64 nValue) = 0;
    virtual bool GetLobbyData64(CSteamID steamIDLobby, const char* pchKey, int64* pResult) = 0;
    virtual const char* GetLobbyData(CSteamID steamIDLobby, const char* pchKey) = 0;
    virtual bool DeleteLobbyData(CSteamID steamIDLobby, const char* pchKey) = 0;
    virtual int GetLobbyMemberCount(CSteamID steamIDLobby) = 0;
    virtual CSteamID GetLobbyMemberByIndex(CSteamID steamIDLobby, int iMember) = 0;
    virtual const char* GetLobbyMemberData(CSteamID steamIDLobby, CSteamID steamIDMember, const char* pchKey) = 0;
    virtual void SetLobbyMemberData(CSteamID steamIDLobby, const char* pchKey, const char* pchValue) = 0;
    virtual void SetLobbyType(CSteamID steamIDLobby, int eLobbyType) = 0;
    virtual void SetLobbyGameServer(CSteamID steamIDLobby, uint32 unGameServerIP, uint16 usGameServerPort, CSteamID steamIDGameServer) = 0;
    virtual bool GetLobbyGameServer(CSteamID steamIDLobby, uint32* punGameServerIP, uint16* pusGameServerPort, CSteamID* psteamIDGameServer) = 0;
    virtual bool SetLobbyMemberLimit(CSteamID steamIDLobby, int cMaxMembers) = 0;
    virtual int GetLobbyMemberLimit(CSteamID steamIDLobby) = 0;
    virtual bool SetLobbyJoinable(CSteamID steamIDLobby, bool bJoinable) = 0;
    virtual bool GetLobbyJoinable(CSteamID steamIDLobby) = 0;
    virtual void LeaveLobby(CSteamID steamIDLobby) = 0;
    virtual void InviteUserToLobby(CSteamID steamIDLobby, CSteamID steamIDInvitee) = 0;
    virtual int GetLobbyInviteList() = 0;
    virtual bool GetLobbyInviteDetails(CSteamID steamIDLobby, int iInvite, CSteamID* psteamIDInviter, bool* pbLocked) = 0;
    virtual void RespondToLobbyInvite(CSteamID steamIDLobby, bool bAccept) = 0;
    virtual void SetLobbyOwner(CSteamID steamIDLobby, CSteamID steamIDNewOwner) = 0;
    virtual void SetLobbyOfficer(CSteamID steamIDLobby, CSteamID steamIDNewOfficer) = 0;
    virtual void SetLobbyAchievementDetails(CSteamID steamIDLobby, const char* pchAchievementID, int nDetails) = 0;
    virtual void SetLobbyHosted(CSteamID steamIDLobby, bool bHosted) = 0;
    virtual void SetHostedLobbyMobile(bool bMobile) = 0;
};

class ISteamUserStats {
public:
    virtual bool RequestCurrentStats() = 0;
    virtual bool GetStat(const char* pchName, int* pData) = 0;
    virtual bool GetStat0(const char* pchName, float* pData) = 0;
    virtual bool SetStat(const char* pchName, int nData) = 0;
    virtual bool SetStat0(const char* pchName, float fData) = 0;
    virtual bool UpdateAvgRateStat(const char* pchName, float flCountThisSession, double dSessionLength) = 0;
    virtual bool GetAchievement(const char* pchName, bool* pbAchieved) = 0;
    virtual bool SetAchievement(const char* pchName) = 0;
    virtual bool ClearAchievement(const char* pchName) = 0;
    virtual bool StoreStats() = 0;
    virtual int GetAchievementIcon(const char* pchName) = 0;
    virtual const char* GetAchievementDisplayAttribute(const char* pchName, const char* pchKey) = 0;
    virtual bool IndicateAchievementProgress(const char* pchName, int nCurProgress, int nMaxProgress) = 0;
    virtual bool RequestGlobalStats(int nHistoryDays) = 0;
    virtual bool GetGlobalStat(const char* pchStatName, int64* pData) = 0;
    virtual bool GetGlobalStat0(const char* pchStatName, double* pData) = 0;
    virtual int GetGlobalStatHistory(const char* pchStatName, int64* pData, int cData) = 0;
    virtual int GetGlobalStatHistory0(const char* pchStatName, double* pData, int cData) = 0;
    virtual bool FindLeaderboard(const char* pchLeaderboardName) = 0;
    virtual bool FindOrCreateLeaderboard(const char* pchLeaderboardName, int eSortMethod, int eDisplayType) = 0;
    virtual bool GetLeaderboardEntryCount(int hSteamLeaderboard, int* pEntryCount) = 0;
    virtual bool GetLeaderboardSortMethod(int hSteamLeaderboard, int* pSortMethod) = 0;
    virtual bool GetLeaderboardDisplayType(int hSteamLeaderboard, int* pDisplayType) = 0;
    virtual bool DownloadLeaderboardEntries(int hSteamLeaderboard, int eLeaderboardDataRequest, int nRangeStart, int nRangeEnd) = 0;
    virtual bool GetDownloadedLeaderboardEntry(int hSteamLeaderboard, int index, int* pEntry, void* pDetails, int cDetailsMax) = 0;
    virtual bool AttachLeaderboardUGC(int hSteamLeaderboard, UGCHandle_t hUGC) = 0;
};

class ISteamClient {
public:
    virtual HSteamUser CreateSteamUser() = 0;
    virtual void* CreateSteamVPNPipe() = 0;
    virtual void* CreateP2PPipe(int bEnable) = 0;
    virtual void* CreateGameServerVPNPipe() = 0;
    virtual ISteamUser* GetISteamUser(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual ISteamFriends* GetISteamFriends(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual ISteamUtils* GetISteamUtils(const char* pchVersion) = 0;
    virtual ISteamApps* GetISteamApps(const char* pchVersion) = 0;
    virtual ISteamNetworking* GetISteamNetworking(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual ISteamMatchmaking* GetISteamMatchmaking(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual ISteamUserStats* GetISteamUserStats(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual void* GetISteamHTTP(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual void* GetISteamController(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual void* GetISteamUGC(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual void* GetISteamAppList(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual void* GetISteamRemoteStorage(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual void* GetISteamScreenshots(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual void* GetISteamVideo(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual void* GetISteamMusic(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual void* GetISteamHTMLSurface(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual void* GetISteamInventory(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual void* GetISteamParentalSettings(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual void* GetISteamParties(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual void* GetISteamRemotePlay(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual void* GetISteamNetworkingSockets(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual void* GetISteamNetworkingMessages(HSteamUser hSteamUser, const char* pchVersion) = 0;
    virtual void* GetISteamNetworkingUtils(const char* pchVersion) = 0;
};

class CSteamClient : public ISteamClient {
public:
    HSteamUser CreateSteamUser() override { return 1; }
    void* CreateSteamVPNPipe() override { return nullptr; }
    void* CreateP2PPipe(int bEnable) override { return nullptr; }
    void* CreateGameServerVPNPipe() override { return nullptr; }
    ISteamUser* GetISteamUser(HSteamUser hSteamUser, const char* pchVersion) override;
    ISteamFriends* GetISteamFriends(HSteamUser hSteamUser, const char* pchVersion) override;
    ISteamUtils* GetISteamUtils(const char* pchVersion) override;
    ISteamApps* GetISteamApps(const char* pchVersion) override;
    ISteamNetworking* GetISteamNetworking(HSteamUser hSteamUser, const char* pchVersion) override;
    ISteamMatchmaking* GetISteamMatchmaking(HSteamUser hSteamUser, const char* pchVersion) override;
    ISteamUserStats* GetISteamUserStats(HSteamUser hSteamUser, const char* pchVersion) override;
    void* GetISteamHTTP(HSteamUser hSteamUser, const char* pchVersion) override { return nullptr; }
    void* GetISteamController(HSteamUser hSteamUser, const char* pchVersion) override { return nullptr; }
    void* GetISteamUGC(HSteamUser hSteamUser, const char* pchVersion) override { return nullptr; }
    void* GetISteamAppList(HSteamUser hSteamUser, const char* pchVersion) override { return nullptr; }
    void* GetISteamRemoteStorage(HSteamUser hSteamUser, const char* pchVersion) override { return nullptr; }
    void* GetISteamScreenshots(HSteamUser hSteamUser, const char* pchVersion) override { return nullptr; }
    void* GetISteamVideo(HSteamUser hSteamUser, const char* pchVersion) override { return nullptr; }
    void* GetISteamMusic(HSteamUser hSteamUser, const char* pchVersion) override { return nullptr; }
    void* GetISteamHTMLSurface(HSteamUser hSteamUser, const char* pchVersion) override { return nullptr; }
    void* GetISteamInventory(HSteamUser hSteamUser, const char* pchVersion) override { return nullptr; }
    void* GetISteamParentalSettings(HSteamUser hSteamUser, const char* pchVersion) override { return nullptr; }
    void* GetISteamParties(HSteamUser hSteamUser, const char* pchVersion) override { return nullptr; }
    void* GetISteamRemotePlay(HSteamUser hSteamUser, const char* pchVersion) override { return nullptr; }
    void* GetISteamNetworkingSockets(HSteamUser hSteamUser, const char* pchVersion) override { return nullptr; }
    void* GetISteamNetworkingMessages(HSteamUser hSteamUser, const char* pchVersion) override { return nullptr; }
    void* GetISteamNetworkingUtils(const char* pchVersion) override { return nullptr; }
};

class CSteamUser : public ISteamUser {
public:
    HSteamUser GetHSteamUser() override { return m_hSteamUser; }
    bool BLoggedOn() override { return m_bLoggedOn; }
    CSteamID GetSteamID() override { return m_steamID; }
    bool BIsSameUser(HSteamUser hUser) override { return hUser == m_hSteamUser; }
    int InitiateGameConnection(void* pAuthBlob, int cbMaxAuthBlob, CSteamID steamID, uint32 unGameServerIP, uint16 usGameServerPort, bool bSecure) override { return 0; }
    void TerminateGameConnection(uint32 unGameServerIP, uint16 usGameServerPort) override {}
    void TerminateGameConnection2(uint32 unGameServerIP, uint16 usGameServerPort) override {}
    void TrackAppUsageEvent(CGameID gameID, int eAppUsageEvent, const char* pchExtraInfo) override {}
    bool GetUserDataFolder(char* pchBuffer, int cubBuffer) override { 
        if (cubBuffer > 0) { strcpy_s(pchBuffer, cubBuffer, "."); }
        return true;
    }
    void StartVoiceRecording() override { m_bVoiceRecording = true; }
    void StopVoiceRecording() override { m_bVoiceRecording = false; }
    int GetVoiceAvailable(bool bCompressed) override { return 0; }
    int GetVoiceNeeded(bool bCompressed) override { return 0; }
    int GetVoice(char* pDestBuffer, int cbDestBufferSize, bool bCompressed) override { return 0; }
    int GetVoiceOptimalSampleRate() override { return 11025; }
    int GetAuthSessionTicket(void* pTicket, int cbMaxTicket, uint32* pcbTicket) override { return 0; }
    void CancelAuthTicket(uint32 hAuthTicket) override {}
    int BeginAuthSession(const void* pAuthTicket, int cbAuthTicket, CSteamID steamID) override { return 0; }
    void EndAuthSession(CSteamID steamID) override {}
    bool IsVACBanned(int nVACBanIndex) override { return false; }
    void RequireShowVACBannedScreen(int nVACBanIndex) override {}
    int GetGameBadgeLevel(int nSeries) override { return 0; }
    void SetDurationControlOnlineState(int nNewState) override {}
    bool BIsDurationControlEnabled() override { return false; }
    int GetSteamGuardDetails() override { return 0; }
    bool BIsTwoFactorEnabled() override { return m_bTwoFactorEnabled; }
    int GetMarketEligibility() override { return 0; }
    bool BIsPhoneIdentifying() override { return false; }
    bool BIsPhoneRequireVerification() override { return false; }
    bool BIsPhoneVerified() override { return m_bPhoneVerified; }
    bool BIsAppOwned(int nAppID) override { return true; }

    void SetAppID(AppId_t appID) { m_nAppID = appID; }
    void SetLoggedOn(bool bLoggedOn) { m_bLoggedOn = bLoggedOn; }
    void SetSteamID(CSteamID steamID) { m_steamID = steamID; }
    void SetPhoneVerified(bool bVerified) { m_bPhoneVerified = bVerified; }
    void SetTwoFactorEnabled(bool bEnabled) { m_bTwoFactorEnabled = bEnabled; }

private:
    HSteamUser m_hSteamUser = 1;
    CSteamID m_steamID = 0x110000100001;
    AppId_t m_nAppID = 10;
    bool m_bLoggedOn = true;
    bool m_bVoiceRecording = false;
    bool m_bPhoneVerified = false;
    bool m_bTwoFactorEnabled = false;
};

class CSteamFriends : public ISteamFriends {
public:
    const char* GetPersonaName() override { return m_playerName; }
    bool SetPersonaName(const char* pchPersonaName) override { 
        if (pchPersonaName) { strcpy_s(m_playerName, pchPersonaName); }
        return true;
    }
    int GetPersonaState() override { return m_personaState; }
    CSteamID GetSteamFriends() override { return CSteamID(0); }
    int GetFriendCount(int iFriendFlags) override { return 0; }
    CSteamID GetFriendByIndex(int iFriend, int iFriendFlags) override { return CSteamID(0); }
    CSteamID GetFriendSteamID(int iFriend) override { return CSteamID(0); }
    int GetFriendRelationship(CSteamID steamID) override { return 0; }
    const char* GetFriendPersonaName(CSteamID steamID) override { return ""; }
    int GetFriendPersonaState(CSteamID steamID) override { return 0; }
    bool GetFriendGamePlayed(CSteamID steamID, FriendGameInfo_t* pGamePlayInfo) override { return false; }
    const char* GetFriendGameName(CSteamID steamID) override { return ""; }
    int GetFriendRegions(CSteamID steamID) override { return 0; }
    int GetClanCount() override { return 0; }
    CSteamID GetClanByIndex(int iClan) override { return CSteamID(0); }
    const char* GetClanName(CSteamID steamID) override { return ""; }
    const char* GetClanTag(CSteamID steamID) override { return ""; }
    bool GetClanActivityCounts(CSteamID steamID, int* pnOnline, int* pnInGame, int* pnChatting) override { 
        if (pnOnline) *pnOnline = 0; 
        if (pnInGame) *pnInGame = 0; 
        if (pnChatting) *pnChatting = 0; 
        return true; 
    }
    int DownloadClanActivityCounts(CSteamID* psteamIDClans, int cClans) override { return 0; }
    int GetFriendsGroupCount() override { return 0; }
    int GetFriendsGroupIDByIndex(int iFG) override { return 0; }
    const char* GetFriendsGroupName(int FriendsGroupID) override { return ""; }
    int GetFriendsGroupMembersCount(int FriendsGroupID) override { return 0; }
    void GetFriendsGroupMembersList(int FriendsGroupID, CSteamID* pOutSteamIDMembers, int cMembersArraySize) override {}
    bool HasFriend(CSteamID steamID, int iFriendFlags) override { return false; }
    int GetClanOfficerCount(CSteamID steamID) override { return 0; }
    CSteamID GetClanOfficerByIndex(CSteamID steamID, int iOfficer) override { return CSteamID(0); }
    void RequestClanOfficerList(CSteamID steamID) override {}
    void SetRichPresence(const char* pchKey, const char* pchValue) override {}
    void ClearRichPresence() override { memset(m_richPresence, 0, sizeof(m_richPresence)); }
    const char* GetFriendRichPresence(const char* pchKey) override { return ""; }
    int GetFriendRichPresenceKeyCount(CSteamID steamID) override { return 0; }
    const char* GetFriendRichPresenceKeyByIndex(CSteamID steamID, int iKey) override { return ""; }
    void RequestFriendRichPresence(CSteamID steamID) override {}
    bool InviteUserToClan(CSteamID steamIDClan, CSteamID steamIDInvitee) override { return false; }
    bool InviteUserToGame(CSteamID steamID, const char* pchConnectionString) override { return false; }
    int GetFollowerCount(CSteamID steamID) override { return 0; }
    bool IsFollowing(CSteamID steamID) override { return false; }
    int GetFollowingCount() override { return 0; }
    CSteamID GetFollowingByIndex(int iIndex) override { return CSteamID(0); }

    void SetPersonaState(int state) { m_personaState = state; }

private:
    char m_playerName[64] = "Player";
    int m_personaState = 1;
    char m_richPresence[64][32];
};

class CSteamUtils : public ISteamUtils {
public:
    AppId_t GetAppID() override { return m_nAppID; }
    bool IsOverlayEnabled() override { return true; }
    bool BOverlayNeedsPresent() override { return false; }
    void SetOverlayNotificationPosition(const char* pchNotificationUILanguage) override {}
    bool IsSteamRunning() override { return true; }
    const char* GetSteamUILanguage() override { return "english"; }
    uint32 GetServerRealTime() override { return m_serverTime; }
    int GetSecondsSinceAppActive() override { return 0; }
    int GetSecondsSinceComputerActive() override { return 0; }
    int GetConnectedUniverse() override { return 1; }
    int GetCurrentBatteryPower() override { return 100; }
    bool IsVRHeadsetStreamingEnabled() override { return false; }
    void SetVRHeadsetStreamingEnabled(bool bEnabled) override {}
    bool IsSteamInBigPictureMode() override { return false; }
    bool IsSteamChinaLauncher() override { return false; }
    bool IsSteamRunningOnSteamDeck() override { return false; }
    void StartVRDashboard() override {}
    bool IsVRDashboardVisible() override { return false; }
    bool BIsSteamInstalled() override { return true; }
    const char* GetSteamInstallPath() override { return "."; }
    int GetSteamBridgeVersion() override { return 0; }
    bool BIsBridgeRemotePlaying() override { return false; }
    bool BIsBridgeRunning() override { return false; }

    void SetAppID(AppId_t appID) { m_nAppID = appID; }
    void UpdateServerTime() { m_serverTime = GetTickCount() / 1000; }
    int GetBuildID() { return 8689; }
    bool IsSteamChina() { return false; }

private:
    AppId_t m_nAppID = 10;
    uint32 m_serverTime = 0;
};

class CSteamApps : public ISteamApps {
public:
    bool BIsAppInstalled(AppId_t appID) override { return appID == 10; }
    bool BIsGameInstalled() override { return true; }
    bool BIsSubscribed() override { return true; }
    bool BIsVACBanned() override { return false; }
    bool BIsCybercafe() override { return false; }
    bool BIsOffline() override { return false; }
    const char* GetAppName() override { return "Counter-Strike"; }
    int GetAppBuildId() override { return m_nBuildID; }
    const char* GetAppInstallDir(AppId_t appID, char* pchBuffer, int cchBuffer) override {
        if (cchBuffer > 0) { strcpy_s(pchBuffer, cchBuffer, "."); }
        return pchBuffer;
    }
    bool BIsDLCInstalled(AppId_t appID) override { return false; }
    bool BIsDlcInstalled(AppId_t appID) { return BIsDLCInstalled(appID); }
    int GetDLCCount() override { return 0; }
    bool BGetDLCDataByIndex(int iDLC, AppId_t* pAppID, bool* pbAvailable, char* pchName, int cchNameBufferSize) override { return false; }
    void InstallDLC(AppId_t appID) override {}
    void UninstallDLC(AppId_t appID) override {}
    bool IsTimedTrial() override { return false; }
    bool BIsTimedTrial() { return IsTimedTrial(); }
    bool BIsFreeApp(AppId_t appID) override { return false; }
    bool BIsSubscribedApp(AppId_t appID) override { return true; }
    bool BIsSubscribedFromFamilySharing() override { return false; }
    bool BIsLowViolence() override { return false; }
    const char* GetCurrentGameLanguage() override { return "english"; }
    const char* GetAvailableGameLanguages() override { return "english"; }
    const char* GetBetaName() override { return ""; }
    const char* GetCurrentBetaName() { return GetBetaName(); }
    const char* GetLaunchCommandLine() override { return ""; }
    const char* GetLaunchQueryParam(const char* pchKey) override { return ""; }
    bool BGetAppInstallDir(AppId_t appID, char* buf, int len) { return GetAppInstallDir(appID, buf, len) != nullptr; }
    CSteamID GetAppOwner() { return CSteamID(0x110000100001); }

    void SetAppBuildId(int nBuildID) { m_nBuildID = nBuildID; }

private:
    int m_nBuildID = 8689;
};

class CSteamNetworking : public ISteamNetworking {
public:
    bool SendP2PPacket(CSteamID steamIDRemote, const void* pData, uint32 cubData, int nSendFlags, int nChannel) override { return false; }
    bool IsP2PPacketAvailable(uint32* pcubDataSize, int nChannel) override { return false; }
    bool ReadP2PPacket(void* pDest, uint32 cubDest, uint32* pcubMsgSize, CSteamID* psteamIDRemote, int nChannel) override { return false; }
    bool AcceptP2PSessionWithUser(CSteamID steamIDRemote) override { return false; }
    bool CloseP2PSessionWithUser(CSteamID steamIDRemote) override { return false; }
    bool CloseP2PChannelWithUser(CSteamID steamIDRemote, int nChannel) override { return false; }
    SNetListenSocket_t CreateP2PListenSocket(int nSteamConnectPort, int nOptions, int nUserData) override { return 0; }
    SNetSocket_t CreateP2PConnectionSocket(CSteamID steamIDTarget, int nSteamPort, int nOptions, int nUserData) override { return 0; }
    SNetSocket_t ConnectP2P(const char* pszSteamID, int nSteamConnectPort, int nOptions, int nUserData) override { return 0; }
    bool DestroySocket(SNetSocket_t hSocket, bool bNotifyRemote) override { return false; }
    bool DestroyListenSocket(SNetListenSocket_t hSocket, bool bNotifyRemote) override { return false; }
    bool SendDataOnSocket(SNetSocket_t hSocket, const void* pData, uint32 cubData, bool bReliable) override { return false; }
    bool IsDataAvailableOnSocket(SNetSocket_t hSocket, uint32* pcubDataSize) override { return false; }
    bool RetrieveDataFromSocket(SNetSocket_t hSocket, void* pDest, uint32 cubDest, uint32* pcubMsgSize) override { return false; }
    bool IsListening(SNetListenSocket_t hSocket) override { return false; }
    SNetSocket_t GetP2PSessionConnectionInfo(CSteamID steamIDRemote, int* pi_snaux, int* pi_rfcong, int* pi_sdsend, uint64* pulTimeout) override { return 0; }
    int GetP2PSessionState(CSteamID steamIDRemote, void* pConnectionState) override { return 0; }
    bool SetP2PSessionSettings(int nChannel, bool bAllowRelay) override { return false; }
    bool SetP2PSessionDefaultTimeout(int nTimeout) override { return false; }
    void SetAlwaysRelay(bool bAlwaysRelay) override {}
    bool BAllowP2PPacketRelay(bool bAllow) override { return false; }
};

class CSteamMatchmaking : public ISteamMatchmaking {
public:
    int GetFavoriteGameCount() override { return 0; }
    bool GetFavoriteGame(int iGame, AppId_t* pnAppID, uint32* pnIP, uint16* pnConnPort, uint16* pnQueryPort, uint32* punFlags, uint32* pRTime32LastPlayedOnServer) override { return false; }
    int AddFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer) override { return 0; }
    bool RemoveFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags) override { return false; }
    int GetServerCount(int iFirst, int iLast) override { return 0; }
    bool GetServerDetails(int iServer, uint32* pnIP, uint16* pnQueryPort, uint16* pnConnPort, uint8* pchName) override { return false; }
    int AddServerToFavorites(uint32 nIP, uint16 nQueryPort, uint16 nConnPort, uint32 unAccountFlags) override { return 0; }
    bool RemoveServerFromFavorites(uint32 nIP, uint16 nQueryPort) override { return false; }
    int PingServer(uint32 unIP, uint16 usPort, uint32* pFullServerProgress) override { return 0; }
    int ServerListRequest(char* pchServerListURL) override { return 0; }
    bool GetServerPingToServerRank(int a, int b, int c) override { return false; }
    int CreateQueryPortServer(int a, bool b, const char* c) override { return 0; }
    void RequestLobbyList() override {}
    int GetLobbyListRequestResults(char* pchServerListURL) override { return 0; }
    void AddRequestLobbyListStringFilter(const char* pchKey, const char* pchValue, int nValueType) override {}
    void AddRequestLobbyListNumericalFilter(const char* pchKey, int nValue, int nComparisonType) override {}
    void AddRequestLobbyListNearValueFilter(const char* pchKey, int nValue) override {}
    CSteamID GetLobbyByIndex(int iLobby) override { return CSteamID(0); }
    void CreateLobby(int bPrivate) override {}
    void SetLobbyData(CSteamID steamIDLobby, const char* pchKey, const char* pchValue) override {}
    int GetLobbyDataCount(CSteamID steamIDLobby) override { return 0; }
    bool GetLobbyDataByIndex(CSteamID steamIDLobby, int iLobbyData, char* pchKey, int cchKeyBufferSize, char* pchValue, int cchValueBufferSize) override { return false; }
    void SetLobbyData64(CSteamID steamIDLobby, const char* pchKey, int64 nValue) override {}
    bool GetLobbyData64(CSteamID steamIDLobby, const char* pchKey, int64* pResult) override { return false; }
    const char* GetLobbyData(CSteamID steamIDLobby, const char* pchKey) override { return ""; }
    bool DeleteLobbyData(CSteamID steamIDLobby, const char* pchKey) override { return false; }
    int GetLobbyMemberCount(CSteamID steamIDLobby) override { return 0; }
    CSteamID GetLobbyMemberByIndex(CSteamID steamIDLobby, int iMember) override { return CSteamID(0); }
    const char* GetLobbyMemberData(CSteamID steamIDLobby, CSteamID steamIDMember, const char* pchKey) override { return ""; }
    void SetLobbyMemberData(CSteamID steamIDLobby, const char* pchKey, const char* pchValue) override {}
    void SetLobbyType(CSteamID steamIDLobby, int eLobbyType) override {}
    void SetLobbyGameServer(CSteamID steamIDLobby, uint32 unGameServerIP, uint16 usGameServerPort, CSteamID steamIDGameServer) override {}
    bool GetLobbyGameServer(CSteamID steamIDLobby, uint32* punGameServerIP, uint16* pusGameServerPort, CSteamID* psteamIDGameServer) override { return false; }
    bool SetLobbyMemberLimit(CSteamID steamIDLobby, int cMaxMembers) override { return false; }
    int GetLobbyMemberLimit(CSteamID steamIDLobby) override { return 0; }
    bool SetLobbyJoinable(CSteamID steamIDLobby, bool bJoinable) override { return false; }
    bool GetLobbyJoinable(CSteamID steamIDLobby) override { return false; }
    void LeaveLobby(CSteamID steamIDLobby) override {}
    void InviteUserToLobby(CSteamID steamIDLobby, CSteamID steamIDInvitee) override {}
    int GetLobbyInviteList() override { return 0; }
    bool GetLobbyInviteDetails(CSteamID steamIDLobby, int iInvite, CSteamID* psteamIDInviter, bool* pbLocked) override { return false; }
    void RespondToLobbyInvite(CSteamID steamIDLobby, bool bAccept) override {}
    void SetLobbyOwner(CSteamID steamIDLobby, CSteamID steamIDNewOwner) override {}
    void SetLobbyOfficer(CSteamID steamIDLobby, CSteamID steamIDNewOfficer) override {}
    void SetLobbyAchievementDetails(CSteamID steamIDLobby, const char* pchAchievementID, int nDetails) override {}
    void SetLobbyHosted(CSteamID steamIDLobby, bool bHosted) override {}
    void SetHostedLobbyMobile(bool bMobile) override {}
};

class CSteamUserStats : public ISteamUserStats {
public:
    bool RequestCurrentStats() override { return true; }
    bool GetStat(const char* pchName, int* pData) override { if (pData) *pData = 0; return true; }
    bool GetStat0(const char* pchName, float* pData) override { if (pData) *pData = 0.0f; return true; }
    bool SetStat(const char* pchName, int nData) override { return true; }
    bool SetStat0(const char* pchName, float fData) override { return true; }
    bool UpdateAvgRateStat(const char* pchName, float flCountThisSession, double dSessionLength) override { return true; }
    bool GetAchievement(const char* pchName, bool* pbAchieved) override { if (pbAchieved) *pbAchieved = false; return true; }
    bool SetAchievement(const char* pchName) override { return true; }
    bool ClearAchievement(const char* pchName) override { return true; }
    bool StoreStats() override { return true; }
    int GetAchievementIcon(const char* pchName) override { return 0; }
    const char* GetAchievementDisplayAttribute(const char* pchName, const char* pchKey) override { return ""; }
    bool IndicateAchievementProgress(const char* pchName, int nCurProgress, int nMaxProgress) override { return true; }
    bool RequestGlobalStats(int nHistoryDays) override { return true; }
    bool GetGlobalStat(const char* pchStatName, int64* pData) override { if (pData) *pData = 0; return true; }
    bool GetGlobalStat0(const char* pchStatName, double* pData) override { if (pData) *pData = 0.0; return true; }
    int GetGlobalStatHistory(const char* pchStatName, int64* pData, int cData) override { return 0; }
    int GetGlobalStatHistory0(const char* pchStatName, double* pData, int cData) override { return 0; }
    bool FindLeaderboard(const char* pchLeaderboardName) override { return false; }
    bool FindOrCreateLeaderboard(const char* pchLeaderboardName, int eSortMethod, int eDisplayType) override { return false; }
    bool GetLeaderboardEntryCount(int hSteamLeaderboard, int* pEntryCount) override { if (pEntryCount) *pEntryCount = 0; return true; }
    bool GetLeaderboardSortMethod(int hSteamLeaderboard, int* pSortMethod) override { if (pSortMethod) *pSortMethod = 0; return true; }
    bool GetLeaderboardDisplayType(int hSteamLeaderboard, int* pDisplayType) override { if (pDisplayType) *pDisplayType = 0; return true; }
    bool DownloadLeaderboardEntries(int hSteamLeaderboard, int eLeaderboardDataRequest, int nRangeStart, int nRangeEnd) override { return false; }
    bool GetDownloadedLeaderboardEntry(int hSteamLeaderboard, int index, int* pEntry, void* pDetails, int cDetailsMax) override { return false; }
    bool AttachLeaderboardUGC(int hSteamLeaderboard, uint64 hUGC) override { return false; }
};

class ISteamAppList { public: virtual ~ISteamAppList() {} };
class ISteamController { public: virtual ~ISteamController() {} };
class ISteamHTMLSurface { public: virtual ~ISteamHTMLSurface() {} };
class ISteamHTTP { public: virtual ~ISteamHTTP() {} };
class ISteamInput { public: virtual ~ISteamInput() {} };
class ISteamInventory { public: virtual ~ISteamInventory() {} };
class ISteamMatchmakingClient { public: virtual ~ISteamMatchmakingClient() {} };
class ISteamMatchmakingServers { public: virtual ~ISteamMatchmakingServers() {} };
class ISteamMusic {
public:
    virtual ~ISteamMusic() {}
    virtual bool BIsEnabled() { return false; }
    virtual bool BIsPlaying() { return false; }
    virtual int GetPlaybackStatus() { return 0; }
    virtual float GetVolume() { return 0.0f; }
    virtual void Pause() {}
    virtual void Play() {}
    virtual void PlayNext() {}
    virtual void PlayPrevious() {}
    virtual void SetVolume(float flVolume) {}
};
class ISteamNetworkingSockets {
public:
    virtual ~ISteamNetworkingSockets() {}
    virtual int AcceptConnection(int hConn) { return 0; }
    virtual int BeginAsyncRequestFakeIP(int nRemotePort) { return 0; }
    virtual int CloseConnection(int hPeer, int nReason, const char* pDebug) { return 0; }
    virtual int CloseListenSocket(int hSocket) { return 0; }
    virtual int ConfigureConnectionLanes(int hConn, int nNumLanes, const int* pLanes) { return 0; }
    virtual int ConnectByIPAddress(const char* pAddr, int nPort) { return 0; }
    virtual int ConnectCallback(int nCallback, int pData) { return 0; }
    virtual int ConnectConnect(const char* pConnInfo) { return 0; }
    virtual int ConnectP2P(const char* pSteamId, int nPort, int nFlags) { return 0; }
    virtual int ConnectP2PCustomSignaling(int pSignaling) { return 0; }
    virtual int ConnectP2PRelay(const char* pSteamIdRelay, int nPort) { return 0; }
    virtual int CreateFakeIPPair(int nFlags) { return 0; }
    virtual int CreateHostedDedicatedServerListenSocket(int nPort, int nFlags) { return 0; }
    virtual int CreateListenSocketIP(const char* pAddr, int nPort, int nFlags) { return 0; }
    virtual int CreateListenSocketP2P(int nVirtualPort, int nFlags) { return 0; }
    virtual int CreateListenSocketP2PFakeIP(int nVirtualPort, int nFlags) { return 0; }
    virtual int CreatePollGroup() { return 0; }
    virtual int CreateSocketPair(int nFlags) { return 0; }
    virtual int DestroyFakeIPPair(int nIP) { return 0; }
    virtual int DestroyPollGroup(int hPollGroup) { return 0; }
    virtual int EndFakeIPPair(int nIP) { return 0; }
    virtual int FindRelayAuthTicketForServer(const char* pServerAddr, int nPort) { return 0; }
    virtual int FlushMessagesOnConnection(int hConn) { return 0; }
    virtual int GetAuthenticationStatus() { return 0; }
    virtual int GetCertificateRequest(int* pcbCertificate, void* pCertificate) { return 0; }
    virtual int GetConnectionInfo(int hConn, int* pInfo) { return 0; }
    virtual int GetConnectionName(int hConn, char* pName, int nMaxLen) { return 0; }
    virtual int GetConnectionRealTimeStatus(int hConn, int* pStatus, int nCallback) { return 0; }
    virtual int GetDetailedConnectionStatus(int hConn, char* pBuf, int cbBuf) { return 0; }
    virtual int GetFakeIP(int hConn, int* pIP, int* pPort) { return 0; }
    virtual int GetGameCoordinatorServerLogin(int hServer, int* pCallback) { return 0; }
    virtual int GetHostedDedicatedServerAddress(int* pAddr) { return 0; }
    virtual int GetHostedDedicatedServerPOPID() { return 0; }
    virtual int GetHostedDedicatedServerPort() { return 0; }
    virtual int GetIdentity(int* pIdentity) { return 0; }
    virtual int GetListenSocketAddress(int hSocket, char* pAddr, int* pPort) { return 0; }
    virtual int GetRemoteFakeIPForConnection(int hConn, int* pIP) { return 0; }
    virtual int InitAuthentication() { return 0; }
    virtual int ReceivedRelayAuthTicket(const void* pTicket, int cbTicket) { return 0; }
    virtual int ReceiveMessagesOnConnection(int hConn, int nMaxMessages) { return 0; }
    virtual int ReceiveMessagesOnPollGroup(int hPollGroup, int nMaxMessages) { return 0; }
    virtual int ReceivedP2PCustomSignal(const void* pMsg, int cbMsg, int* pCallback) { return 0; }
    virtual int ReceivedRelayAuthTicket(const void* pTicket, int cbTicket, int nCallback) { return 0; }
    virtual int ResetIdentity() { return 0; }
    virtual int SendMessageToConnection(int hConn, const void* pData, int cbData, int nSendFlags) { return 0; }
    virtual int SendRemoteHost(const char* pHost) { return 0; }
    virtual int SendSignal(const void* pSignal, int cbSignal) { return 0; }
    virtual int SetConnectionUserData(int hConn, int nUserData) { return 0; }
    virtual int SetGlobalConfigValueBool(const char* pName, bool bValue) { return 0; }
    virtual int SetGlobalConfigValueFloat(const char* pName, float fValue) { return 0; }
    virtual int SetGlobalConfigValueInt32(const char* pName, int nValue) { return 0; }
    virtual int SetGlobalConfigValueInt64(const char* pName, long long nValue) { return 0; }
    virtual int SetGlobalConfigValueString(const char* pName, const char* pValue) { return 0; }
    virtual int SetLocalMode(int nMode) { return 0; }
    virtual int SetConnectionConfigValueBool(int hConn, const char* pName, bool bValue) { return 0; }
    virtual int SetConnectionConfigValueFloat(int hConn, const char* pName, float fValue) { return 0; }
    virtual int SetConnectionConfigValueInt32(int hConn, const char* pName, int nValue) { return 0; }
    virtual int SetConnectionConfigValueInt64(int hConn, const char* pName, long long nValue) { return 0; }
    virtual int SetConnectionConfigValueString(int hConn, const char* pName, const char* pValue) { return 0; }
};
class ISteamNetworkingMessages {
public:
    virtual ~ISteamNetworkingMessages() {}
    virtual int ReceiveMessagesOnChannel(int nChannel, int nMaxMessages) { return 0; }
    virtual int SendMessageToUser(int nSteamId, const void* pData, int cbData, int nSendFlags) { return 0; }
};
class ISteamNetworkingUtils { public: virtual ~ISteamNetworkingUtils() {} };
class ISteamParentalSettings { public: virtual ~ISteamParentalSettings() {} };
class ISteamParties { public: virtual ~ISteamParties() {} };
class ISteamRemotePlay { public: virtual ~ISteamRemotePlay() {} };
class ISteamRemoteStorage { public: virtual ~ISteamRemoteStorage() {} };
class ISteamScreenshots { public: virtual ~ISteamScreenshots() {} };
class ISteamUGC { public: virtual ~ISteamUGC() {} };
class ISteamVideo { public: virtual ~ISteamVideo() {} };

class CSteamAppList : public ISteamAppList {};
class CSteamController : public ISteamController {};
class CSteamHTMLSurface : public ISteamHTMLSurface {};
class CSteamHTTP : public ISteamHTTP {};
class CSteamInput : public ISteamInput {};
class CSteamInventory : public ISteamInventory {};
class CSteamMatchmakingClient : public ISteamMatchmakingClient {};
class CSteamMatchmakingServers : public ISteamMatchmakingServers {};
class CSteamMusic : public ISteamMusic {
public:
    bool BIsEnabled() override { return m_bEnabled; }
    bool BIsPlaying() override { return m_bPlaying; }
    int GetPlaybackStatus() override { return m_nStatus; }
    float GetVolume() override { return m_flVolume; }
    void Pause() override { m_bPlaying = false; }
    void Play() override { m_bPlaying = true; }
    void PlayNext() override {}
    void PlayPrevious() override {}
    void SetVolume(float flVolume) override { m_flVolume = flVolume; }
private:
    bool m_bEnabled = true;
    bool m_bPlaying = false;
    int m_nStatus = 0;
    float m_flVolume = 1.0f;
};
class CSteamNetworkingSockets : public ISteamNetworkingSockets {
public:
    int AcceptConnection(int hConn) override { return 0; }
    int BeginAsyncRequestFakeIP(int nRemotePort) override { return 0; }
    int CloseConnection(int hPeer, int nReason, const char* pDebug) override { return 0; }
    int CloseListenSocket(int hSocket) override { return 0; }
    int ConfigureConnectionLanes(int hConn, int nNumLanes, const int* pLanes) override { return 0; }
    int ConnectByIPAddress(const char* pAddr, int nPort) override { return 0; }
    int ConnectCallback(int nCallback, int pData) override { return 0; }
    int ConnectConnect(const char* pConnInfo) override { return 0; }
    int ConnectP2P(const char* pSteamId, int nPort, int nFlags) override { return 0; }
    int ConnectP2PCustomSignaling(int pSignaling) override { return 0; }
    int ConnectP2PRelay(const char* pSteamIdRelay, int nPort) override { return 0; }
    int CreateFakeIPPair(int nFlags) override { return 0; }
    int CreateHostedDedicatedServerListenSocket(int nPort, int nFlags) override { return 0; }
    int CreateListenSocketIP(const char* pAddr, int nPort, int nFlags) override { return 0; }
    int CreateListenSocketP2P(int nVirtualPort, int nFlags) override { return 0; }
    int CreateListenSocketP2PFakeIP(int nVirtualPort, int nFlags) override { return 0; }
    int CreatePollGroup() override { return 0; }
    int CreateSocketPair(int nFlags) override { return 0; }
    int DestroyFakeIPPair(int nIP) override { return 0; }
    int DestroyPollGroup(int hPollGroup) override { return 0; }
    int EndFakeIPPair(int nIP) override { return 0; }
    int FindRelayAuthTicketForServer(const char* pServerAddr, int nPort) override { return 0; }
    int FlushMessagesOnConnection(int hConn) override { return 0; }
    int GetAuthenticationStatus() override { return 0; }
    int GetCertificateRequest(int* pcbCertificate, void* pCertificate) override { return 0; }
    int GetConnectionInfo(int hConn, int* pInfo) override { return 0; }
    int GetConnectionName(int hConn, char* pName, int nMaxLen) override { if (pName && nMaxLen > 0) pName[0] = 0; return 0; }
    int GetConnectionRealTimeStatus(int hConn, int* pStatus, int nCallback) override { return 0; }
    int GetDetailedConnectionStatus(int hConn, char* pBuf, int cbBuf) override { if (pBuf && cbBuf > 0) pBuf[0] = 0; return 0; }
    int GetFakeIP(int hConn, int* pIP, int* pPort) override { return 0; }
    int GetGameCoordinatorServerLogin(int hServer, int* pCallback) override { return 0; }
    int GetHostedDedicatedServerAddress(int* pAddr) override { return 0; }
    int GetHostedDedicatedServerPOPID() override { return 0; }
    int GetHostedDedicatedServerPort() override { return 0; }
    int GetIdentity(int* pIdentity) override { return 0; }
    int GetListenSocketAddress(int hSocket, char* pAddr, int* pPort) override { return 0; }
    int GetRemoteFakeIPForConnection(int hConn, int* pIP) override { return 0; }
    int InitAuthentication() override { return 0; }
    int ReceivedRelayAuthTicket(const void* pTicket, int cbTicket) override { return 0; }
    int ReceiveMessagesOnConnection(int hConn, int nMaxMessages) override { return 0; }
    int ReceiveMessagesOnPollGroup(int hPollGroup, int nMaxMessages) override { return 0; }
    int ReceivedP2PCustomSignal(const void* pMsg, int cbMsg, int* pCallback) override { return 0; }
    int ReceivedRelayAuthTicket(const void* pTicket, int cbTicket, int nCallback) override { return 0; }
    int ResetIdentity() override { return 0; }
    int SendMessageToConnection(int hConn, const void* pData, int cbData, int nSendFlags) override { return 0; }
    int SendRemoteHost(const char* pHost) override { return 0; }
    int SendSignal(const void* pSignal, int cbSignal) override { return 0; }
    int SetConnectionUserData(int hConn, int nUserData) override { return 0; }
    int SetGlobalConfigValueBool(const char* pName, bool bValue) override { return 0; }
    int SetGlobalConfigValueFloat(const char* pName, float fValue) override { return 0; }
    int SetGlobalConfigValueInt32(const char* pName, int nValue) override { return 0; }
    int SetGlobalConfigValueInt64(const char* pName, long long nValue) override { return 0; }
    int SetGlobalConfigValueString(const char* pName, const char* pValue) override { return 0; }
    int SetLocalMode(int nMode) override { return 0; }
    int SetConnectionConfigValueBool(int hConn, const char* pName, bool bValue) override { return 0; }
    int SetConnectionConfigValueFloat(int hConn, const char* pName, float fValue) override { return 0; }
    int SetConnectionConfigValueInt32(int hConn, const char* pName, int nValue) override { return 0; }
    int SetConnectionConfigValueInt64(int hConn, const char* pName, long long nValue) override { return 0; }
    int SetConnectionConfigValueString(int hConn, const char* pName, const char* pValue) override { return 0; }
};
class CSteamNetworkingMessages : public ISteamNetworkingMessages {
public:
    int ReceiveMessagesOnChannel(int nChannel, int nMaxMessages) override { return 0; }
    int SendMessageToUser(int nSteamId, const void* pData, int cbData, int nSendFlags) override { return 0; }
};
class CSteamNetworkingUtils : public ISteamNetworkingUtils {};
class CSteamParentalSettings : public ISteamParentalSettings {};
class CSteamParties : public ISteamParties {};
class CSteamRemotePlay : public ISteamRemotePlay {};
class CSteamRemoteStorage : public ISteamRemoteStorage {};
class CSteamScreenshots : public ISteamScreenshots {};
class CSteamUGC : public ISteamUGC {};
class CSteamVideo : public ISteamVideo {};
