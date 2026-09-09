#include "steam_friends.h"
#include <cstring>

CSteamFriends::CSteamFriends()
    : m_personaName("Player"),
      m_personaState(1)
{
}

const char* CSteamFriends::GetPersonaName() {
    return m_personaName.c_str();
}

bool CSteamFriends::SetPersonaName(const char* pchPersonaName) {
    if (pchPersonaName) {
        m_personaName = pchPersonaName;
        return true;
    }
    return false;
}

int CSteamFriends::GetPersonaState() {
    return m_personaState;
}

CSteamID CSteamFriends::GetSteamFriends() {
    return CSteamID(0);
}

int CSteamFriends::GetFriendCount(int iFriendFlags) {
    return 0;
}

CSteamID CSteamFriends::GetFriendByIndex(int iFriend, int iFriendFlags) {
    return CSteamID(0);
}

CSteamID CSteamFriends::GetFriendSteamID(int iFriend) {
    return CSteamID(0);
}

int CSteamFriends::GetFriendRelationship(CSteamID steamID) {
    return 0;
}

const char* CSteamFriends::GetFriendPersonaName(CSteamID steamID) {
    return "";
}

int CSteamFriends::GetFriendPersonaState(CSteamID steamID) {
    return 0;
}

bool CSteamFriends::GetFriendGamePlayed(CSteamID steamID, FriendGameInfo_t* pGamePlayInfo) {
    return false;
}

const char* CSteamFriends::GetFriendGameName(CSteamID steamID) {
    return "";
}

int CSteamFriends::GetFriendRegions(CSteamID steamID) {
    return 0;
}

int CSteamFriends::GetClanCount() {
    return 0;
}

CSteamID CSteamFriends::GetClanByIndex(int iClan) {
    return CSteamID(0);
}

const char* CSteamFriends::GetClanName(CSteamID steamID) {
    return "";
}

const char* CSteamFriends::GetClanTag(CSteamID steamID) {
    return "";
}

bool CSteamFriends::GetClanActivityCounts(CSteamID steamID, int* pnOnline, int* pnInGame, int* pnChatting) {
    if (pnOnline) *pnOnline = 0;
    if (pnInGame) *pnInGame = 0;
    if (pnChatting) *pnChatting = 0;
    return true;
}

int CSteamFriends::DownloadClanActivityCounts(CSteamID* psteamIDClans, int cClans) {
    return 0;
}

int CSteamFriends::GetFriendsGroupCount() {
    return 0;
}

int CSteamFriends::GetFriendsGroupIDByIndex(int iFG) {
    return 0;
}

const char* CSteamFriends::GetFriendsGroupName(int FriendsGroupID) {
    return "";
}

int CSteamFriends::GetFriendsGroupMembersCount(int FriendsGroupID) {
    return 0;
}

void CSteamFriends::GetFriendsGroupMembersList(int FriendsGroupID, CSteamID* pOutSteamIDMembers, int cMembersArraySize) {
}

bool CSteamFriends::HasFriend(CSteamID steamID, int iFriendFlags) {
    return false;
}

int CSteamFriends::GetClanOfficerCount(CSteamID steamID) {
    return 0;
}

CSteamID CSteamFriends::GetClanOfficerByIndex(CSteamID steamID, int iOfficer) {
    return CSteamID(0);
}

void CSteamFriends::RequestClanOfficerList(CSteamID steamID) {
}

void CSteamFriends::SetRichPresence(const char* pchKey, const char* pchValue) {
    if (pchKey && pchValue) {
        m_richPresence[pchKey] = pchValue;
    }
}

void CSteamFriends::ClearRichPresence() {
    m_richPresence.clear();
}

const char* CSteamFriends::GetFriendRichPresence(const char* pchKey) {
    auto it = m_richPresence.find(pchKey);
    if (it != m_richPresence.end()) {
        return it->second.c_str();
    }
    return "";
}

int CSteamFriends::GetFriendRichPresenceKeyCount(CSteamID steamID) {
    return 0;
}

const char* CSteamFriends::GetFriendRichPresenceKeyByIndex(CSteamID steamID, int iKey) {
    return "";
}

void CSteamFriends::RequestFriendRichPresence(CSteamID steamID) {
}

bool CSteamFriends::InviteUserToClan(CSteamID steamIDClan, CSteamID steamIDInvitee) {
    return false;
}

bool CSteamFriends::InviteUserToGame(CSteamID steamID, const char* pchConnectionString) {
    return false;
}

int CSteamFriends::GetFollowerCount(CSteamID steamID) {
    return 0;
}

bool CSteamFriends::IsFollowing(CSteamID steamID) {
    return false;
}

int CSteamFriends::GetFollowingCount() {
    return 0;
}

CSteamID CSteamFriends::GetFollowingByIndex(int iIndex) {
    return CSteamID(0);
}