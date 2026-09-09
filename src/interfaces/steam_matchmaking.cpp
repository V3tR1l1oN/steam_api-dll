#include "steam_matchmaking.h"
#include <cstring>

CSteamMatchmaking::CSteamMatchmaking() : m_nextLobbyID(1) {}

int CSteamMatchmaking::GetFavoriteGameCount() { return 0; }
bool CSteamMatchmaking::GetFavoriteGame(int iGame, AppId_t* pnAppID, uint32* pnIP, uint16* pnConnPort, uint16* pnQueryPort, uint32* punFlags, uint32* pRTime32LastPlayedOnServer) { return false; }
int CSteamMatchmaking::AddFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer) { return 0; }
bool CSteamMatchmaking::RemoveFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags) { return false; }
int CSteamMatchmaking::GetServerCount(int iFirst, int iLast) { return 0; }
bool CSteamMatchmaking::GetServerDetails(int iServer, uint32* pnIP, uint16* pnQueryPort, uint16* pnConnPort, uint8* pchName) { return false; }
int CSteamMatchmaking::AddServerToFavorites(uint32 nIP, uint16 nQueryPort, uint16 nConnPort, uint32 unAccountFlags) { return 0; }
bool CSteamMatchmaking::RemoveServerFromFavorites(uint32 nIP, uint16 nQueryPort) { return false; }
int CSteamMatchmaking::PingServer(uint32 unIP, uint16 usPort, uint32* pFullServerProgress) { return 0; }
int CSteamMatchmaking::ServerListRequest(char* pchServerListURL) { return 0; }
bool CSteamMatchmaking::GetServerPingToServerRank(int a, int b, int c) { return false; }
int CSteamMatchmaking::CreateQueryPortServer(int a, bool b, const char* c) { return 0; }

void CSteamMatchmaking::RequestLobbyList() {
    m_lobbyListResults.clear();
    for (auto& pair : m_lobbies) {
        m_lobbyListResults.push_back(pair.first);
    }
}

int CSteamMatchmaking::GetLobbyListRequestResults(char* pchServerListURL) { return (int)m_lobbyListResults.size(); }

void CSteamMatchmaking::AddRequestLobbyListStringFilter(const char* pchKey, const char* pchValue, int nValueType) {
    m_stringFilters.push_back(std::string(pchKey) + "=" + pchValue);
}

void CSteamMatchmaking::AddRequestLobbyListNumericalFilter(const char* pchKey, int nValue, int nComparisonType) {
    m_numericFilters.push_back({pchKey, nValue});
}

void CSteamMatchmaking::AddRequestLobbyListNearValueFilter(const char* pchKey, int nValue) {}

CSteamID CSteamMatchmaking::GetLobbyByIndex(int iLobby) {
    if (iLobby >= 0 && iLobby < (int)m_lobbyListResults.size()) {
        return m_lobbyListResults[iLobby];
    }
    return CSteamID(0);
}

void CSteamMatchmaking::CreateLobby(int bPrivate) {
    CSteamID newID(m_nextLobbyID++);
    LobbyData data;
    data.lobbyID = newID;
    data.owner = newID;
    data.maxMembers = 32;
    data.joinable = true;
    data.lobbyType = bPrivate ? 1 : 0;
    m_lobbies[newID] = data;
    m_currentLobbyID = newID;
}

void CSteamMatchmaking::SetLobbyData(CSteamID steamIDLobby, const char* pchKey, const char* pchValue) {
    auto it = m_lobbies.find(steamIDLobby);
    if (it != m_lobbies.end()) {
        it->second.metadata[pchKey] = pchValue;
    }
}

int CSteamMatchmaking::GetLobbyDataCount(CSteamID steamIDLobby) {
    auto it = m_lobbies.find(steamIDLobby);
    return it != m_lobbies.end() ? (int)it->second.metadata.size() : 0;
}

bool CSteamMatchmaking::GetLobbyDataByIndex(CSteamID steamIDLobby, int iLobbyData, char* pchKey, int cchKeyBufferSize, char* pchValue, int cchValueBufferSize) {
    auto it = m_lobbies.find(steamIDLobby);
    if (it == m_lobbies.end()) return false;
    int idx = 0;
    for (auto& pair : it->second.metadata) {
        if (idx == iLobbyData) {
            strncpy(pchKey, pair.first.c_str(), cchKeyBufferSize);
            strncpy(pchValue, pair.second.c_str(), cchValueBufferSize);
            return true;
        }
        idx++;
    }
    return false;
}

void CSteamMatchmaking::SetLobbyData64(CSteamID steamIDLobby, const char* pchKey, int64 nValue) {
    char buf[32];
    sprintf(buf, "%lld", nValue);
    SetLobbyData(steamIDLobby, pchKey, buf);
}

bool CSteamMatchmaking::GetLobbyData64(CSteamID steamIDLobby, const char* pchKey, int64* pResult) {
    const char* val = GetLobbyData(steamIDLobby, pchKey);
    if (val && *val) {
        *pResult = atoll(val);
        return true;
    }
    return false;
}

const char* CSteamMatchmaking::GetLobbyData(CSteamID steamIDLobby, const char* pchKey) {
    auto it = m_lobbies.find(steamIDLobby);
    if (it != m_lobbies.end()) {
        auto dataIt = it->second.metadata.find(pchKey);
        if (dataIt != it->second.metadata.end()) {
            return dataIt->second.c_str();
        }
    }
    return "";
}

bool CSteamMatchmaking::DeleteLobbyData(CSteamID steamIDLobby, const char* pchKey) {
    auto it = m_lobbies.find(steamIDLobby);
    if (it != m_lobbies.end()) {
        return it->second.metadata.erase(pchKey) > 0;
    }
    return false;
}

int CSteamMatchmaking::GetLobbyMemberCount(CSteamID steamIDLobby) {
    auto it = m_lobbies.find(steamIDLobby);
    return it != m_lobbies.end() ? (int)it->second.members.size() : 0;
}

CSteamID CSteamMatchmaking::GetLobbyMemberByIndex(CSteamID steamIDLobby, int iMember) {
    auto it = m_lobbies.find(steamIDLobby);
    if (it != m_lobbies.end() && iMember >= 0 && iMember < (int)it->second.members.size()) {
        return it->second.members[iMember];
    }
    return CSteamID(0);
}

const char* CSteamMatchmaking::GetLobbyMemberData(CSteamID steamIDLobby, CSteamID steamIDMember, const char* pchKey) {
    return "";
}

void CSteamMatchmaking::SetLobbyMemberData(CSteamID steamIDLobby, const char* pchKey, const char* pchValue) {}

void CSteamMatchmaking::SetLobbyType(CSteamID steamIDLobby, int eLobbyType) {
    auto it = m_lobbies.find(steamIDLobby);
    if (it != m_lobbies.end()) {
        it->second.lobbyType = eLobbyType;
    }
}

void CSteamMatchmaking::SetLobbyGameServer(CSteamID steamIDLobby, uint32 unGameServerIP, uint16 usGameServerPort, CSteamID steamIDGameServer) {}

bool CSteamMatchmaking::GetLobbyGameServer(CSteamID steamIDLobby, uint32* punGameServerIP, uint16* pusGameServerPort, CSteamID* psteamIDGameServer) { return false; }

bool CSteamMatchmaking::SetLobbyMemberLimit(CSteamID steamIDLobby, int cMaxMembers) {
    auto it = m_lobbies.find(steamIDLobby);
    if (it != m_lobbies.end()) {
        it->second.maxMembers = cMaxMembers;
        return true;
    }
    return false;
}

int CSteamMatchmaking::GetLobbyMemberLimit(CSteamID steamIDLobby) {
    auto it = m_lobbies.find(steamIDLobby);
    return it != m_lobbies.end() ? it->second.maxMembers : 0;
}

bool CSteamMatchmaking::SetLobbyJoinable(CSteamID steamIDLobby, bool bJoinable) {
    auto it = m_lobbies.find(steamIDLobby);
    if (it != m_lobbies.end()) {
        it->second.joinable = bJoinable;
        return true;
    }
    return false;
}

bool CSteamMatchmaking::GetLobbyJoinable(CSteamID steamIDLobby) {
    auto it = m_lobbies.find(steamIDLobby);
    return it != m_lobbies.end() ? it->second.joinable : false;
}

void CSteamMatchmaking::LeaveLobby(CSteamID steamIDLobby) {
    m_lobbies.erase(steamIDLobby);
}

void CSteamMatchmaking::InviteUserToLobby(CSteamID steamIDLobby, CSteamID steamIDInvitee) {}

int CSteamMatchmaking::GetLobbyInviteList() { return 0; }
bool CSteamMatchmaking::GetLobbyInviteDetails(CSteamID steamIDLobby, int iInvite, CSteamID* psteamIDInviter, bool* pbLocked) { return false; }
void CSteamMatchmaking::RespondToLobbyInvite(CSteamID steamIDLobby, bool bAccept) {}

void CSteamMatchmaking::SetLobbyOwner(CSteamID steamIDLobby, CSteamID steamIDNewOwner) {
    auto it = m_lobbies.find(steamIDLobby);
    if (it != m_lobbies.end()) {
        it->second.owner = steamIDNewOwner;
    }
}

void CSteamMatchmaking::SetLobbyOfficer(CSteamID steamIDLobby, CSteamID steamIDNewOfficer) {}
void CSteamMatchmaking::SetLobbyAchievementDetails(CSteamID steamIDLobby, const char* pchAchievementID, int nDetails) {}
void CSteamMatchmaking::SetLobbyHosted(CSteamID steamIDLobby, bool bHosted) {}
void CSteamMatchmaking::SetHostedLobbyMobile(bool bMobile) {}