#pragma once
#include "../../include/steam/steam_api_goldsrc.h"
#include <string>
#include <map>

class CSteamFriends : public ISteamFriends {
public:
    CSteamFriends();
    virtual ~CSteamFriends() = default;

    // ISteamFriends implementation
    const char* GetPersonaName() override;
    bool SetPersonaName(const char* pchPersonaName) override;
    int GetPersonaState() override;
    CSteamID GetSteamFriends() override;
    int GetFriendCount(int iFriendFlags) override;
    CSteamID GetFriendByIndex(int iFriend, int iFriendFlags) override;
    CSteamID GetFriendSteamID(int iFriend) override;
    int GetFriendRelationship(CSteamID steamID) override;
    const char* GetFriendPersonaName(CSteamID steamID) override;
    int GetFriendPersonaState(CSteamID steamID) override;
    bool GetFriendGamePlayed(CSteamID steamID, FriendGameInfo_t* pGamePlayInfo) override;
    const char* GetFriendGameName(CSteamID steamID) override;
    int GetFriendRegions(CSteamID steamID) override;
    int GetClanCount() override;
    CSteamID GetClanByIndex(int iClan) override;
    const char* GetClanName(CSteamID steamID) override;
    const char* GetClanTag(CSteamID steamID) override;
    bool GetClanActivityCounts(CSteamID steamID, int* pnOnline, int* pnInGame, int* pnChatting) override;
    int DownloadClanActivityCounts(CSteamID* psteamIDClans, int cClans) override;
    int GetFriendsGroupCount() override;
    int GetFriendsGroupIDByIndex(int iFG) override;
    const char* GetFriendsGroupName(int FriendsGroupID) override;
    int GetFriendsGroupMembersCount(int FriendsGroupID) override;
    void GetFriendsGroupMembersList(int FriendsGroupID, CSteamID* pOutSteamIDMembers, int cMembersArraySize) override;
    bool HasFriend(CSteamID steamID, int iFriendFlags) override;
    int GetClanOfficerCount(CSteamID steamID) override;
    CSteamID GetClanOfficerByIndex(CSteamID steamID, int iOfficer) override;
    void RequestClanOfficerList(CSteamID steamID) override;
    void SetRichPresence(const char* pchKey, const char* pchValue) override;
    void ClearRichPresence() override;
    const char* GetFriendRichPresence(const char* pchKey) override;
    int GetFriendRichPresenceKeyCount(CSteamID steamID) override;
    const char* GetFriendRichPresenceKeyByIndex(CSteamID steamID, int iKey) override;
    void RequestFriendRichPresence(CSteamID steamID) override;
    bool InviteUserToClan(CSteamID steamIDClan, CSteamID steamIDInvitee) override;
    bool InviteUserToGame(CSteamID steamID, const char* pchConnectionString) override;
    int GetFollowerCount(CSteamID steamID) override;
    bool IsFollowing(CSteamID steamID) override;
    int GetFollowingCount() override;
    CSteamID GetFollowingByIndex(int iIndex) override;

private:
    std::string m_personaName;
    int m_personaState;
    std::map<std::string, std::string> m_richPresence;
};