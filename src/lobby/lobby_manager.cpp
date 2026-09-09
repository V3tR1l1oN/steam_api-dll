#include "lobby_manager.h"

LobbyManager& LobbyManager::Instance() {
    static LobbyManager instance;
    return instance;
}

CSteamID LobbyManager::CreateLobby(bool bPrivate) {
    std::lock_guard<std::mutex> lock(m_mutex);
    CSteamID newID(m_nextLobbyID.GetAccountID() + 1);
    m_nextLobbyID = newID;

    LobbyData data;
    data.lobbyID = newID;
    data.owner = newID;
    data.maxMembers = 32;
    data.joinable = true;
    data.lobbyType = bPrivate ? 1 : 0;
    m_lobbies[newID] = data;
    return newID;
}

bool LobbyManager::JoinLobby(CSteamID lobbyID, CSteamID user) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_lobbies.find(lobbyID);
    if (it == m_lobbies.end()) return false;
    if (!it->second.joinable) return false;
    if ((int)it->second.members.size() >= it->second.maxMembers) return false;
    it->second.members.push_back(user);
    return true;
}

void LobbyManager::LeaveLobby(CSteamID lobbyID, CSteamID user) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_lobbies.find(lobbyID);
    if (it == m_lobbies.end()) return;
    auto& members = it->second.members;
    members.erase(std::remove(members.begin(), members.end(), user), members.end());
    if (members.empty()) {
        m_lobbies.erase(it);
    }
}

void LobbyManager::SetLobbyData(CSteamID lobbyID, const std::string& key, const std::string& value) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_lobbies.find(lobbyID);
    if (it != m_lobbies.end()) {
        it->second.metadata[key] = value;
    }
}

std::string LobbyManager::GetLobbyData(CSteamID lobbyID, const std::string& key) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_lobbies.find(lobbyID);
    if (it != m_lobbies.end()) {
        auto dataIt = it->second.metadata.find(key);
        if (dataIt != it->second.metadata.end()) {
            return dataIt->second;
        }
    }
    return "";
}

std::vector<CSteamID> LobbyManager::GetLobbyList() {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::vector<CSteamID> result;
    for (auto& pair : m_lobbies) {
        result.push_back(pair.first);
    }
    return result;
}

int LobbyManager::GetMemberCount(CSteamID lobbyID) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_lobbies.find(lobbyID);
    return it != m_lobbies.end() ? (int)it->second.members.size() : 0;
}

std::vector<CSteamID> LobbyManager::GetMembers(CSteamID lobbyID) {
    std::lock_guard<std::mutex> lock(m_mutex);
    auto it = m_lobbies.find(lobbyID);
    if (it != m_lobbies.end()) {
        return it->second.members;
    }
    return {};
}