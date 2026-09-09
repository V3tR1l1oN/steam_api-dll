#pragma once
#include "../../include/steam/steam_api_goldsrc.h"
#include <map>
#include <vector>
#include <string>
#include <mutex>

struct LobbyData {
    CSteamID lobbyID;
    CSteamID owner;
    std::map<std::string, std::string> metadata;
    std::vector<CSteamID> members;
    int maxMembers;
    bool joinable;
    int lobbyType;
};

class LobbyManager {
public:
    static LobbyManager& Instance();

    CSteamID CreateLobby(bool bPrivate);
    bool JoinLobby(CSteamID lobbyID, CSteamID user);
    void LeaveLobby(CSteamID lobbyID, CSteamID user);
    void SetLobbyData(CSteamID lobbyID, const std::string& key, const std::string& value);
    std::string GetLobbyData(CSteamID lobbyID, const std::string& key);
    std::vector<CSteamID> GetLobbyList();
    int GetMemberCount(CSteamID lobbyID);
    std::vector<CSteamID> GetMembers(CSteamID lobbyID);

private:
    LobbyManager() = default;
    std::map<CSteamID, LobbyData> m_lobbies;
    std::mutex m_mutex;
    CSteamID m_nextLobbyID;
};