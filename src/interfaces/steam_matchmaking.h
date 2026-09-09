#pragma once
#include "../../include/steam/steam_api_goldsrc.h"
#include <map>
#include <vector>
#include <string>

struct LobbyData {
    CSteamID lobbyID;
    CSteamID owner;
    std::map<std::string, std::string> metadata;
    std::vector<CSteamID> members;
    int maxMembers;
    bool joinable;
    int lobbyType;
};

class CSteamMatchmaking : public ISteamMatchmaking {
public:
    CSteamMatchmaking();
    virtual ~CSteamMatchmaking() = default;

    // ISteamMatchmaking implementation
    int GetFavoriteGameCount() override;
    bool GetFavoriteGame(int iGame, AppId_t* pnAppID, uint32* pnIP, uint16* pnConnPort, uint16* pnQueryPort, uint32* punFlags, uint32* pRTime32LastPlayedOnServer) override;
    int AddFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer) override;
    bool RemoveFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags) override;
    int GetServerCount(int iFirst, int iLast) override;
    bool GetServerDetails(int iServer, uint32* pnIP, uint16* pnQueryPort, uint16* pnConnPort, uint8* pchName) override;
    int AddServerToFavorites(uint32 nIP, uint16 nQueryPort, uint16 nConnPort, uint32 unAccountFlags) override;
    bool RemoveServerFromFavorites(uint32 nIP, uint16 nQueryPort) override;
    int PingServer(uint32 unIP, uint16 usPort, uint32* pFullServerProgress) override;
    int ServerListRequest(char* pchServerListURL) override;
    bool GetServerPingToServerRank(int a, int b, int c) override;
    int CreateQueryPortServer(int a, bool b, const char* c) override;
    void RequestLobbyList() override;
    int GetLobbyListRequestResults(char* pchServerListURL) override;
    void AddRequestLobbyListStringFilter(const char* pchKey, const char* pchValue, int nValueType) override;
    void AddRequestLobbyListNumericalFilter(const char* pchKey, int nValue, int nComparisonType) override;
    void AddRequestLobbyListNearValueFilter(const char* pchKey, int nValue) override;
    CSteamID GetLobbyByIndex(int iLobby) override;
    void CreateLobby(int bPrivate) override;
    void SetLobbyData(CSteamID steamIDLobby, const char* pchKey, const char* pchValue) override;
    int GetLobbyDataCount(CSteamID steamIDLobby) override;
    bool GetLobbyDataByIndex(CSteamID steamIDLobby, int iLobbyData, char* pchKey, int cchKeyBufferSize, char* pchValue, int cchValueBufferSize) override;
    void SetLobbyData64(CSteamID steamIDLobby, const char* pchKey, int64 nValue) override;
    bool GetLobbyData64(CSteamID steamIDLobby, const char* pchKey, int64* pResult) override;
    const char* GetLobbyData(CSteamID steamIDLobby, const char* pchKey) override;
    bool DeleteLobbyData(CSteamID steamIDLobby, const char* pchKey) override;
    int GetLobbyMemberCount(CSteamID steamIDLobby) override;
    CSteamID GetLobbyMemberByIndex(CSteamID steamIDLobby, int iMember) override;
    const char* GetLobbyMemberData(CSteamID steamIDLobby, CSteamID steamIDMember, const char* pchKey) override;
    void SetLobbyMemberData(CSteamID steamIDLobby, const char* pchKey, const char* pchValue) override;
    void SetLobbyType(CSteamID steamIDLobby, int eLobbyType) override;
    void SetLobbyGameServer(CSteamID steamIDLobby, uint32 unGameServerIP, uint16 usGameServerPort, CSteamID steamIDGameServer) override;
    bool GetLobbyGameServer(CSteamID steamIDLobby, uint32* punGameServerIP, uint16* pusGameServerPort, CSteamID* psteamIDGameServer) override;
    bool SetLobbyMemberLimit(CSteamID steamIDLobby, int cMaxMembers) override;
    int GetLobbyMemberLimit(CSteamID steamIDLobby) override;
    bool SetLobbyJoinable(CSteamID steamIDLobby, bool bJoinable) override;
    bool GetLobbyJoinable(CSteamID steamIDLobby) override;
    void LeaveLobby(CSteamID steamIDLobby) override;
    void InviteUserToLobby(CSteamID steamIDLobby, CSteamID steamIDInvitee) override;
    int GetLobbyInviteList() override;
    bool GetLobbyInviteDetails(CSteamID steamIDLobby, int iInvite, CSteamID* psteamIDInviter, bool* pbLocked) override;
    void RespondToLobbyInvite(CSteamID steamIDLobby, bool bAccept) override;
    void SetLobbyOwner(CSteamID steamIDLobby, CSteamID steamIDNewOwner) override;
    void SetLobbyOfficer(CSteamID steamIDLobby, CSteamID steamIDNewOfficer) override;
    void SetLobbyAchievementDetails(CSteamID steamIDLobby, const char* pchAchievementID, int nDetails) override;
    void SetLobbyHosted(CSteamID steamIDLobby, bool bHosted) override;
    void SetHostedLobbyMobile(bool bMobile) override;

private:
    std::map<CSteamID, LobbyData> m_lobbies;
    std::vector<CSteamID> m_lobbyListResults;
    std::vector<std::string> m_stringFilters;
    std::vector<std::pair<std::string, int>> m_numericFilters;
    CSteamID m_currentLobbyID;
    int m_nextLobbyID;
};