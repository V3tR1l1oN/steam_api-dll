// sdk_guard.cpp — vtable-совместимые реализации всех интерфейсов, запрашиваемых
// движком GoldSrc, по официальной раскладке SteamWorks SDK.
// Каждый метод — безопасная заглушка, возвращающая «правдоподобное» значение.
#include "sdk_guard.h"
#include <cstring>
#include <time.h>

static const char* kEmpty = "";

// ---------- SdkSteamFriends (80 методов) ----------
int SdkSteamFriends::GetFriendCount(int) { return 0; }
const char* SdkSteamFriends::GetPersonaName() { return "Player"; }
SteamAPICall_t SdkSteamFriends::SetPersonaName(const char* n) { return 0; }
int SdkSteamFriends::GetPersonaState() { return 1; }
SdkSteamID SdkSteamFriends::GetFriendByIndex(int, int) { return SdkSteamID(); }
int SdkSteamFriends::GetFriendRelationship(SdkSteamID) { return 0; }
int SdkSteamFriends::GetFriendPersonaState(SdkSteamID) { return 0; }
const char* SdkSteamFriends::GetFriendPersonaName(SdkSteamID) { return kEmpty; }
bool SdkSteamFriends::GetFriendGamePlayed(SdkSteamID, void*) { return false; }
const char* SdkSteamFriends::GetFriendPersonaNameHistory(SdkSteamID, int) { return kEmpty; }
int SdkSteamFriends::GetFriendSteamLevel(SdkSteamID) { return 0; }
const char* SdkSteamFriends::GetPlayerNickname(SdkSteamID) { return kEmpty; }
int SdkSteamFriends::GetFriendsGroupCount() { return 0; }
short SdkSteamFriends::GetFriendsGroupIDByIndex(int) { return 0; }
const char* SdkSteamFriends::GetFriendsGroupName(short) { return kEmpty; }
int SdkSteamFriends::GetFriendsGroupMembersCount(short) { return 0; }
void SdkSteamFriends::GetFriendsGroupMembersList(short, SdkSteamID*, int) {}
bool SdkSteamFriends::HasFriend(SdkSteamID, int) { return false; }
int SdkSteamFriends::GetClanCount() { return 0; }
SdkSteamID SdkSteamFriends::GetClanByIndex(int) { return SdkSteamID(); }
const char* SdkSteamFriends::GetClanName(SdkSteamID) { return kEmpty; }
const char* SdkSteamFriends::GetClanTag(SdkSteamID) { return kEmpty; }
bool SdkSteamFriends::GetClanActivityCounts(SdkSteamID, int* a, int* b, int* c) { if (a)*a=0; if (b)*b=0; if (c)*c=0; return false; }
SteamAPICall_t SdkSteamFriends::DownloadClanActivityCounts(SdkSteamID*, int) { return 0; }
int SdkSteamFriends::GetFriendCountFromSource(SdkSteamID) { return 0; }
SdkSteamID SdkSteamFriends::GetFriendFromSourceByIndex(SdkSteamID, int) { return SdkSteamID(); }
bool SdkSteamFriends::IsUserInSource(SdkSteamID, SdkSteamID) { return false; }
void SdkSteamFriends::SetInGameVoiceSpeaking(SdkSteamID, bool) {}
void SdkSteamFriends::ActivateGameOverlay(const char*) {}
void SdkSteamFriends::ActivateGameOverlayToUser(const char*, SdkSteamID) {}
void SdkSteamFriends::ActivateGameOverlayToWebPage(const char*, int) {}
void SdkSteamFriends::ActivateGameOverlayToStore(AppId_t, int) {}
void SdkSteamFriends::SetPlayedWith(SdkSteamID) {}
void SdkSteamFriends::ActivateGameOverlayInviteDialog(SdkSteamID) {}
int SdkSteamFriends::GetSmallFriendAvatar(SdkSteamID) { return 0; }
int SdkSteamFriends::GetMediumFriendAvatar(SdkSteamID) { return 0; }
int SdkSteamFriends::GetLargeFriendAvatar(SdkSteamID) { return 0; }
bool SdkSteamFriends::RequestUserInformation(SdkSteamID, bool) { return false; }
SteamAPICall_t SdkSteamFriends::RequestClanOfficerList(SdkSteamID) { return 0; }
SdkSteamID SdkSteamFriends::GetClanOwner(SdkSteamID) { return SdkSteamID(); }
int SdkSteamFriends::GetClanOfficerCount(SdkSteamID) { return 0; }
SdkSteamID SdkSteamFriends::GetClanOfficerByIndex(SdkSteamID, int) { return SdkSteamID(); }
unsigned int SdkSteamFriends::GetUserRestrictions() { return 0; }
bool SdkSteamFriends::SetRichPresence(const char* k, const char* v) { return true; }
void SdkSteamFriends::ClearRichPresence() {}
const char* SdkSteamFriends::GetFriendRichPresence(SdkSteamID, const char*) { return kEmpty; }
int SdkSteamFriends::GetFriendRichPresenceKeyCount(SdkSteamID) { return 0; }
const char* SdkSteamFriends::GetFriendRichPresenceKeyByIndex(SdkSteamID, int) { return kEmpty; }
void SdkSteamFriends::RequestFriendRichPresence(SdkSteamID) {}
bool SdkSteamFriends::InviteUserToGame(SdkSteamID, const char*) { return false; }
int SdkSteamFriends::GetCoplayFriendCount() { return 0; }
SdkSteamID SdkSteamFriends::GetCoplayFriend(int) { return SdkSteamID(); }
int SdkSteamFriends::GetFriendCoplayTime(SdkSteamID) { return 0; }
AppId_t SdkSteamFriends::GetFriendCoplayGame(SdkSteamID) { return 0; }
SteamAPICall_t SdkSteamFriends::JoinClanChatRoom(SdkSteamID) { return 0; }
bool SdkSteamFriends::LeaveClanChatRoom(SdkSteamID) { return false; }
int SdkSteamFriends::GetClanChatMemberCount(SdkSteamID) { return 0; }
SdkSteamID SdkSteamFriends::GetChatMemberByIndex(SdkSteamID, int) { return SdkSteamID(); }
bool SdkSteamFriends::SendClanChatMessage(SdkSteamID, const char*) { return false; }
int SdkSteamFriends::GetClanChatMessage(SdkSteamID, int, void*, int, int*, SdkSteamID*) { return 0; }
bool SdkSteamFriends::IsClanChatAdmin(SdkSteamID, SdkSteamID) { return false; }
bool SdkSteamFriends::IsClanChatWindowOpenInSteam(SdkSteamID) { return false; }
bool SdkSteamFriends::OpenClanChatWindowInSteam(SdkSteamID) { return false; }
bool SdkSteamFriends::CloseClanChatWindowInSteam(SdkSteamID) { return false; }
bool SdkSteamFriends::SetListenForFriendsMessages(bool) { return false; }
bool SdkSteamFriends::ReplyToFriendMessage(SdkSteamID, const char*) { return false; }
int SdkSteamFriends::GetFriendMessage(SdkSteamID, int, void*, int, int*) { return 0; }
SteamAPICall_t SdkSteamFriends::GetFollowerCount(SdkSteamID) { return 0; }
SteamAPICall_t SdkSteamFriends::IsFollowing(SdkSteamID) { return 0; }
SteamAPICall_t SdkSteamFriends::EnumerateFollowingList(unsigned int) { return 0; }
bool SdkSteamFriends::IsClanPublic(SdkSteamID) { return false; }
bool SdkSteamFriends::IsClanOfficialGameGroup(SdkSteamID) { return false; }
int SdkSteamFriends::GetNumChatsWithUnreadPriorityMessages() { return 0; }
void SdkSteamFriends::ActivateGameOverlayRemotePlayTogetherInviteDialog(SdkSteamID) {}
bool SdkSteamFriends::RegisterProtocolInOverlayBrowser(const char*) { return false; }
void SdkSteamFriends::ActivateGameOverlayInviteDialogConnectString(const char*) {}
SteamAPICall_t SdkSteamFriends::RequestEquippedProfileItems(SdkSteamID) { return 0; }
bool SdkSteamFriends::BHasEquippedProfileItem(SdkSteamID, int) { return false; }
const char* SdkSteamFriends::GetProfileItemPropertyString(SdkSteamID, int, int) { return kEmpty; }
unsigned int SdkSteamFriends::GetProfileItemPropertyUint(SdkSteamID, int, int) { return 0; }

// ---------- SdkSteamApps (30 методов) ----------
bool SdkSteamApps::BIsSubscribed() { return true; }
bool SdkSteamApps::BIsLowViolence() { return false; }
bool SdkSteamApps::BIsCybercafe() { return false; }
bool SdkSteamApps::BIsVACBanned() { return false; }
const char* SdkSteamApps::GetCurrentGameLanguage() { return "english"; }
const char* SdkSteamApps::GetAvailableGameLanguages() { return "english"; }
bool SdkSteamApps::BIsSubscribedApp(AppId_t) { return true; }
bool SdkSteamApps::BIsDlcInstalled(AppId_t) { return false; }
unsigned int SdkSteamApps::GetEarliestPurchaseUnixTime(AppId_t) { return 0; }
bool SdkSteamApps::BIsSubscribedFromFreeWeekend() { return false; }
int SdkSteamApps::GetDLCCount() { return 0; }
bool SdkSteamApps::BGetDLCDataByIndex(int, AppId_t*, bool*, char*, int) { return false; }
void SdkSteamApps::InstallDLC(AppId_t) {}
void SdkSteamApps::UninstallDLC(AppId_t) {}
void SdkSteamApps::RequestAppProofOfPurchaseKey(AppId_t) {}
bool SdkSteamApps::GetCurrentBetaName(char* n, int l) { if (n && l>0) n[0]=0; return false; }
bool SdkSteamApps::MarkContentCorrupt(bool) { return false; }
unsigned int SdkSteamApps::GetInstalledDepots(AppId_t, unsigned int*, unsigned int) { return 0; }
unsigned int SdkSteamApps::GetAppInstallDir(AppId_t, char* folder, unsigned int sz) { if (folder && sz>0) { folder[0]='.'; folder[1]=0; } return 1; }
bool SdkSteamApps::BIsAppInstalled(AppId_t) { return true; }
const char* SdkSteamApps::GetLaunchQueryParam(const char*) { return kEmpty; }
bool SdkSteamApps::GetDlcDownloadProgress(AppId_t, unsigned long long*, unsigned long long*) { return false; }
int SdkSteamApps::GetAppBuildId() { return 8689; }
void SdkSteamApps::RequestAllProofOfPurchaseKeys() {}
SteamAPICall_t SdkSteamApps::GetFileDetails(const char*) { return 0; }
int SdkSteamApps::GetLaunchCommandLine(char* c, int l) { if (c && l>0) c[0]=0; return 0; }
bool SdkSteamApps::BIsSubscribedFromFamilySharing() { return false; }
bool SdkSteamApps::BIsTimedTrial(unsigned int*, unsigned int*) { return false; }
bool SdkSteamApps::SetDlcContext(AppId_t) { return false; }

// ---------- SdkSteamUserStats (45 методов) ----------
bool SdkSteamUserStats::RequestCurrentStats() { return true; }
bool SdkSteamUserStats::GetStatInt(const char*, int* d) { if (d)*d=0; return true; }
bool SdkSteamUserStats::GetStatFloat(const char*, float* d) { if (d)*d=0; return true; }
bool SdkSteamUserStats::SetStatInt(const char*, int) { return true; }
bool SdkSteamUserStats::SetStatFloat(const char*, float) { return true; }
bool SdkSteamUserStats::UpdateAvgRateStat(const char*, float, double) { return true; }
bool SdkSteamUserStats::GetAchievement(const char*, bool* a) { if (a)*a=false; return true; }
bool SdkSteamUserStats::SetAchievement(const char*) { return true; }
bool SdkSteamUserStats::ClearAchievement(const char*) { return true; }
bool SdkSteamUserStats::GetAchievementAndUnlockTime(const char*, bool* a, unsigned int* t) { if (a)*a=false; if (t)*t=0; return true; }
bool SdkSteamUserStats::StoreStats() { return true; }
int SdkSteamUserStats::GetAchievementIcon(const char*) { return 0; }
const char* SdkSteamUserStats::GetAchievementDisplayAttribute(const char*, const char*) { return kEmpty; }
bool SdkSteamUserStats::IndicateAchievementProgress(const char*, unsigned int, unsigned int) { return true; }
unsigned int SdkSteamUserStats::GetNumAchievements() { return 0; }
const char* SdkSteamUserStats::GetAchievementName(unsigned int) { return kEmpty; }
SteamAPICall_t SdkSteamUserStats::RequestUserStats(SdkSteamID) { return 0; }
bool SdkSteamUserStats::GetUserStatInt(SdkSteamID, const char*, int* d) { if (d)*d=0; return true; }
bool SdkSteamUserStats::GetUserStatFloat(SdkSteamID, const char*, float* d) { if (d)*d=0; return true; }
bool SdkSteamUserStats::GetUserAchievement(SdkSteamID, const char*, bool* a) { if (a)*a=false; return true; }
bool SdkSteamUserStats::GetUserAchievementAndUnlockTime(SdkSteamID, const char*, bool* a, unsigned int* t) { if (a)*a=false; if (t)*t=0; return true; }
bool SdkSteamUserStats::ResetAllStats(bool) { return true; }
SteamAPICall_t SdkSteamUserStats::FindOrCreateLeaderboard(const char*, int, int) { return 0; }
SteamAPICall_t SdkSteamUserStats::FindLeaderboard(const char*) { return 0; }
const char* SdkSteamUserStats::GetLeaderboardName(unsigned long long) { return kEmpty; }
int SdkSteamUserStats::GetLeaderboardEntryCount(unsigned long long) { return 0; }
int SdkSteamUserStats::GetLeaderboardSortMethod(unsigned long long) { return 0; }
int SdkSteamUserStats::GetLeaderboardDisplayType(unsigned long long) { return 0; }
SteamAPICall_t SdkSteamUserStats::DownloadLeaderboardEntries(unsigned long long, int, int, int) { return 0; }
SteamAPICall_t SdkSteamUserStats::DownloadLeaderboardEntriesForUsers(unsigned long long, SdkSteamID*, int) { return 0; }
bool SdkSteamUserStats::GetDownloadedLeaderboardEntry(unsigned long long, int, void*, int*, int) { return false; }
SteamAPICall_t SdkSteamUserStats::UploadLeaderboardScore(unsigned long long, int, int, const int*, int) { return 0; }
SteamAPICall_t SdkSteamUserStats::AttachLeaderboardUGC(unsigned long long, unsigned long long) { return 0; }
SteamAPICall_t SdkSteamUserStats::GetNumberOfCurrentPlayers() { return 0; }
SteamAPICall_t SdkSteamUserStats::RequestGlobalAchievementPercentages() { return 0; }
int SdkSteamUserStats::GetMostAchievedAchievementInfo(char*, unsigned int, float*, bool*) { return 0; }
int SdkSteamUserStats::GetNextMostAchievedAchievementInfo(int, char*, unsigned int, float*, bool*) { return 0; }
bool SdkSteamUserStats::GetAchievementAchievedPercent(const char*, float*) { return false; }
SteamAPICall_t SdkSteamUserStats::RequestGlobalStats(int) { return 0; }
bool SdkSteamUserStats::GetGlobalStatInt(const char*, long long* d) { if (d)*d=0; return true; }
bool SdkSteamUserStats::GetGlobalStatFloat(const char*, double* d) { if (d)*d=0; return true; }
int SdkSteamUserStats::GetGlobalStatHistoryInt(const char*, long long*, unsigned int) { return 0; }
int SdkSteamUserStats::GetGlobalStatHistoryFloat(const char*, double*, unsigned int) { return 0; }
bool SdkSteamUserStats::GetAchievementProgressLimitsInt(const char*, int*, int*) { return false; }
bool SdkSteamUserStats::GetAchievementProgressLimitsFloat(const char*, float*, float*) { return false; }

// ---------- SdkSteamNetworking (22 метода) ----------
bool SdkSteamNetworking::SendP2PPacket(SdkSteamID, const void*, unsigned int, int, int) { return false; }
bool SdkSteamNetworking::IsP2PPacketAvailable(unsigned int*, int) { return false; }
bool SdkSteamNetworking::ReadP2PPacket(void*, unsigned int, unsigned int*, SdkSteamID*, int) { return false; }
bool SdkSteamNetworking::AcceptP2PSessionWithUser(SdkSteamID) { return false; }
bool SdkSteamNetworking::CloseP2PSessionWithUser(SdkSteamID) { return false; }
bool SdkSteamNetworking::CloseP2PChannelWithUser(SdkSteamID, int) { return false; }
bool SdkSteamNetworking::GetP2PSessionState(SdkSteamID, void*) { return false; }
bool SdkSteamNetworking::AllowP2PPacketRelay(bool) { return true; }
int SdkSteamNetworking::CreateListenSocket(int, unsigned int, unsigned short, bool) { return 0; }
int SdkSteamNetworking::CreateP2PConnectionSocket(SdkSteamID, int, int, bool) { return 0; }
int SdkSteamNetworking::CreateConnectionSocket(unsigned int, unsigned short, int) { return 0; }
bool SdkSteamNetworking::DestroySocket(int, bool) { return false; }
bool SdkSteamNetworking::DestroyListenSocket(int, bool) { return false; }
bool SdkSteamNetworking::SendDataOnSocket(int, void*, unsigned int, bool) { return false; }
bool SdkSteamNetworking::IsDataAvailableOnSocket(int, unsigned int*) { return false; }
bool SdkSteamNetworking::RetrieveDataFromSocket(int, void*, unsigned int, unsigned int*) { return false; }
bool SdkSteamNetworking::IsDataAvailable(int, unsigned int*, int*) { return false; }
bool SdkSteamNetworking::RetrieveData(int, void*, unsigned int, unsigned int*, int*) { return false; }
bool SdkSteamNetworking::GetSocketInfo(int, SdkSteamID*, int*, unsigned int*, unsigned short*) { return false; }
bool SdkSteamNetworking::GetListenSocketInfo(int, unsigned int*, unsigned short*) { return false; }
int SdkSteamNetworking::GetSocketConnectionType(int) { return 0; }
int SdkSteamNetworking::GetMaxPacketSize(int) { return 0; }

// ---------- SdkSteamMatchmaking (первые 38 методов — lobbies; остальные — server list/GameSearch/beacon) ----------
int SdkSteamMatchmaking::GetFavoriteGameCount() { return 0; }
bool SdkSteamMatchmaking::GetFavoriteGame(int, AppId_t*, unsigned int*, unsigned short*, unsigned short*, unsigned int*, unsigned int*) { return false; }
int SdkSteamMatchmaking::AddFavoriteGame(AppId_t, unsigned int, unsigned short, unsigned short, unsigned int, unsigned int) { return 0; }
bool SdkSteamMatchmaking::RemoveFavoriteGame(AppId_t, unsigned int, unsigned short, unsigned short, unsigned int) { return false; }
SteamAPICall_t SdkSteamMatchmaking::RequestLobbyList() { return 0; }
void SdkSteamMatchmaking::AddRequestLobbyListStringFilter(const char*, const char*, int) {}
void SdkSteamMatchmaking::AddRequestLobbyListNumericalFilter(const char*, int, int) {}
void SdkSteamMatchmaking::AddRequestLobbyListNearValueFilter(const char*, int) {}
void SdkSteamMatchmaking::AddRequestLobbyListFilterSlotsAvailable(int) {}
void SdkSteamMatchmaking::AddRequestLobbyListDistanceFilter(int) {}
void SdkSteamMatchmaking::AddRequestLobbyListResultCountFilter(int) {}
void SdkSteamMatchmaking::AddRequestLobbyListCompatibleMembersFilter(SdkSteamID) {}
SdkSteamID SdkSteamMatchmaking::GetLobbyByIndex(int) { return SdkSteamID(); }
SteamAPICall_t SdkSteamMatchmaking::CreateLobby(int, int) { return 0; }
SteamAPICall_t SdkSteamMatchmaking::JoinLobby(SdkSteamID) { return 0; }
void SdkSteamMatchmaking::LeaveLobby(SdkSteamID) {}
bool SdkSteamMatchmaking::InviteUserToLobby(SdkSteamID, SdkSteamID) { return false; }
int SdkSteamMatchmaking::GetNumLobbyMembers(SdkSteamID) { return 0; }
SdkSteamID SdkSteamMatchmaking::GetLobbyMemberByIndex(SdkSteamID, int) { return SdkSteamID(); }
const char* SdkSteamMatchmaking::GetLobbyData(SdkSteamID, const char*) { return kEmpty; }
bool SdkSteamMatchmaking::SetLobbyData(SdkSteamID, const char*, const char*) { return false; }
int SdkSteamMatchmaking::GetLobbyDataCount(SdkSteamID) { return 0; }
bool SdkSteamMatchmaking::GetLobbyDataByIndex(SdkSteamID, int, char*, int, char*, int) { return false; }
bool SdkSteamMatchmaking::DeleteLobbyData(SdkSteamID, const char*) { return false; }
const char* SdkSteamMatchmaking::GetLobbyMemberData(SdkSteamID, SdkSteamID, const char*) { return kEmpty; }
void SdkSteamMatchmaking::SetLobbyMemberData(SdkSteamID, const char*, const char*) {}
bool SdkSteamMatchmaking::SendLobbyChatMsg(SdkSteamID, const void*, int) { return false; }
int SdkSteamMatchmaking::GetLobbyChatEntry(SdkSteamID, int, SdkSteamID*, void*, int, int*) { return 0; }
bool SdkSteamMatchmaking::RequestLobbyData(SdkSteamID) { return false; }
void SdkSteamMatchmaking::SetLobbyGameServer(SdkSteamID, unsigned int, unsigned short, SdkSteamID) {}
bool SdkSteamMatchmaking::GetLobbyGameServer(SdkSteamID, unsigned int*, unsigned short*, SdkSteamID*) { return false; }
bool SdkSteamMatchmaking::SetLobbyMemberLimit(SdkSteamID, int) { return false; }
int SdkSteamMatchmaking::GetLobbyMemberLimit(SdkSteamID) { return 0; }
bool SdkSteamMatchmaking::SetLobbyType(SdkSteamID, int) { return false; }
bool SdkSteamMatchmaking::SetLobbyJoinable(SdkSteamID, bool) { return false; }
SdkSteamID SdkSteamMatchmaking::GetLobbyOwner(SdkSteamID) { return SdkSteamID(); }
bool SdkSteamMatchmaking::SetLobbyOwner(SdkSteamID, SdkSteamID) { return false; }
bool SdkSteamMatchmaking::SetLinkedLobby(SdkSteamID, SdkSteamID) { return false; }
// Слоты 39-93 (PSN invite, server list callbacks, GameSearch, beacons) — универсальная заглушка не нужна:
// они виртуальные, наследуются автоматически как no-op через общий vtable из заголовка.
// Для точности добавляем пустые тела только для используемых движком.

// SdkSteamUser::GetSteamID: движок вызывает vtable[2] и (по ABI Valve) не передаёт
// sret-указатель, но MSVC генерирует запись по [ebp+8]. При невалидном адресе — AV.
// SEH перехватывает AV, чтобы процесс не умирал.

void SdkSteamMatchmaking::CheckForPSNGameBootInvite(unsigned int) {}
void SdkSteamMatchmaking::ServerResponded(void*, int) {}
void SdkSteamMatchmaking::ServerFailedToRespond(void*, int) {}
void SdkSteamMatchmaking::RefreshComplete(void*, int) {}
void SdkSteamMatchmaking::ServerResponded2(void*) {}
void SdkSteamMatchmaking::ServerFailedToRespond2() {}
void SdkSteamMatchmaking::AddPlayerToList(const char*, int, float) {}
void SdkSteamMatchmaking::PlayersFailedToRespond() {}
void SdkSteamMatchmaking::PlayersRefreshComplete() {}
void SdkSteamMatchmaking::RulesResponded(const char*, const char*) {}
void SdkSteamMatchmaking::RulesFailedToRespond() {}
void SdkSteamMatchmaking::RulesRefreshComplete() {}
void* SdkSteamMatchmaking::RequestInternetServerList(AppId_t, void**, unsigned int, void*) { return nullptr; }
void* SdkSteamMatchmaking::RequestLANServerList(AppId_t, void*) { return nullptr; }
void* SdkSteamMatchmaking::RequestFriendsServerList(AppId_t, void**, unsigned int, void*) { return nullptr; }
void* SdkSteamMatchmaking::RequestFavoritesServerList(AppId_t, void**, unsigned int, void*) { return nullptr; }
void* SdkSteamMatchmaking::RequestHistoryServerList(AppId_t, void**, unsigned int, void*) { return nullptr; }
void* SdkSteamMatchmaking::RequestSpectatorServerList(AppId_t, void**, unsigned int, void*) { return nullptr; }
void SdkSteamMatchmaking::ReleaseRequest(void*) {}
void* SdkSteamMatchmaking::GetServerDetails(void*, int) { return nullptr; }
void SdkSteamMatchmaking::CancelQuery(void*) {}
void SdkSteamMatchmaking::RefreshQuery(void*) {}
bool SdkSteamMatchmaking::IsRefreshing(void*) { return false; }
int SdkSteamMatchmaking::GetServerCount(void*) { return 0; }
void SdkSteamMatchmaking::RefreshServer(void*, int) {}
int SdkSteamMatchmaking::PingServer(unsigned int, unsigned short, void*) { return 0; }
int SdkSteamMatchmaking::PlayerDetails(unsigned int, unsigned short, void*) { return 0; }
int SdkSteamMatchmaking::ServerRules(unsigned int, unsigned short, void*) { return 0; }
void SdkSteamMatchmaking::CancelServerQuery(int) {}
int SdkSteamMatchmaking::AddGameSearchParams(const char*, const char*) { return 0; }
int SdkSteamMatchmaking::SearchForGameWithLobby(SdkSteamID, int, int) { return 0; }
int SdkSteamMatchmaking::SearchForGameSolo(int, int) { return 0; }
int SdkSteamMatchmaking::AcceptGame() { return 0; }
int SdkSteamMatchmaking::DeclineGame() { return 0; }
int SdkSteamMatchmaking::RetrieveConnectionDetails(SdkSteamID, char*, int) { return 0; }
int SdkSteamMatchmaking::EndGameSearch() { return 0; }
int SdkSteamMatchmaking::SetGameHostParams(const char*, const char*) { return 0; }
int SdkSteamMatchmaking::SetConnectionDetails(const char*, int) { return 0; }
int SdkSteamMatchmaking::RequestPlayersForGame(int, int, int) { return 0; }
int SdkSteamMatchmaking::HostConfirmGameStart(unsigned long long) { return 0; }
int SdkSteamMatchmaking::CancelRequestPlayersForGame() { return 0; }
int SdkSteamMatchmaking::SubmitPlayerResult(unsigned long long, SdkSteamID, int) { return 0; }
int SdkSteamMatchmaking::EndGame(unsigned long long) { return 0; }
unsigned int SdkSteamMatchmaking::GetNumActiveBeacons() { return 0; }
unsigned long long SdkSteamMatchmaking::GetBeaconByIndex(unsigned int) { return 0; }
bool SdkSteamMatchmaking::GetBeaconDetails(unsigned long long, SdkSteamID*, void*, char*, int) { return false; }
unsigned long long SdkSteamMatchmaking::JoinParty(unsigned long long) { return 0; }
bool SdkSteamMatchmaking::GetNumAvailableBeaconLocations(void*, unsigned int) { return false; }
bool SdkSteamMatchmaking::GetAvailableBeaconLocations(void*, unsigned int, unsigned int) { return false; }
unsigned long long SdkSteamMatchmaking::CreateBeacon(unsigned int, void*, const char*, const char*) { return 0; }
void SdkSteamMatchmaking::OnReservationCompleted(unsigned long long, SdkSteamID) {}
void SdkSteamMatchmaking::CancelReservation(unsigned long long, SdkSteamID) {}
unsigned long long SdkSteamMatchmaking::ChangeNumOpenSlots(unsigned long long, unsigned int) { return 0; }
bool SdkSteamMatchmaking::DestroyBeacon(unsigned long long) { return false; }
bool SdkSteamMatchmaking::GetBeaconLocationData(void*, int, char*, int) { return false; }
