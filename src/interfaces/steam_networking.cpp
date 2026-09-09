#include "steam_networking.h"
#include <algorithm>

CSteamNetworking::CSteamNetworking() : m_bAlwaysRelay(false) {}

bool CSteamNetworking::SendP2PPacket(CSteamID steamIDRemote, const void* pData, uint32 cubData, int nSendFlags, int nChannel) {
    std::lock_guard<std::mutex> lock(m_mutex);
    P2PPacket packet;
    packet.sender = steamIDRemote;
    packet.data.resize(cubData);
    memcpy(packet.data.data(), pData, cubData);
    packet.channel = nChannel;
    m_incomingPackets[steamIDRemote].push(packet);
    return true;
}

bool CSteamNetworking::IsP2PPacketAvailable(uint32* pcubDataSize, int nChannel) {
    std::lock_guard<std::mutex> lock(m_mutex);
    for (auto& pair : m_incomingPackets) {
        if (!pair.second.empty()) {
            if (pcubDataSize) *pcubDataSize = pair.second.front().data.size();
            return true;
        }
    }
    return false;
}

bool CSteamNetworking::ReadP2PPacket(void* pDest, uint32 cubDest, uint32* pcubMsgSize, CSteamID* psteamIDRemote, int nChannel) {
    std::lock_guard<std::mutex> lock(m_mutex);
    for (auto& pair : m_incomingPackets) {
        if (!pair.second.empty()) {
            auto& packet = pair.second.front();
            if (nChannel == -1 || packet.channel == nChannel) {
                uint32 size = std::min(cubDest, (uint32)packet.data.size());
                memcpy(pDest, packet.data.data(), size);
                if (pcubMsgSize) *pcubMsgSize = packet.data.size();
                if (psteamIDRemote) *psteamIDRemote = packet.sender;
                pair.second.pop();
                return true;
            }
        }
    }
    return false;
}

bool CSteamNetworking::AcceptP2PSessionWithUser(CSteamID steamIDRemote) { return true; }
bool CSteamNetworking::CloseP2PSessionWithUser(CSteamID steamIDRemote) { return true; }
bool CSteamNetworking::CloseP2PChannelWithUser(CSteamID steamIDRemote, int nChannel) { return true; }
SNetListenSocket_t CSteamNetworking::CreateP2PListenSocket(int nSteamConnectPort, int nOptions, int nUserData) { return 0; }
SNetSocket_t CSteamNetworking::CreateP2PConnectionSocket(CSteamID steamIDTarget, int nSteamPort, int nOptions, int nUserData) { return 0; }
SNetSocket_t CSteamNetworking::ConnectP2P(const char* pszSteamID, int nSteamConnectPort, int nOptions, int nUserData) { return 0; }
bool CSteamNetworking::DestroySocket(SNetSocket_t hSocket, bool bNotifyRemote) { return false; }
bool CSteamNetworking::DestroyListenSocket(SNetListenSocket_t hSocket, bool bNotifyRemote) { return false; }
bool CSteamNetworking::SendDataOnSocket(SNetSocket_t hSocket, const void* pData, uint32 cubData, bool bReliable) { return false; }
bool CSteamNetworking::IsDataAvailableOnSocket(SNetSocket_t hSocket, uint32* pcubDataSize) { return false; }
bool CSteamNetworking::RetrieveDataFromSocket(SNetSocket_t hSocket, void* pDest, uint32 cubDest, uint32* pcubMsgSize) { return false; }
bool CSteamNetworking::IsListening(SNetListenSocket_t hSocket) { return false; }
SNetSocket_t CSteamNetworking::GetP2PSessionConnectionInfo(CSteamID steamIDRemote, int* pi_snaux, int* pi_rfcong, int* pi_sdsend, uint64* pulTimeout) { return 0; }
int CSteamNetworking::GetP2PSessionState(CSteamID steamIDRemote, void* pConnectionState) { return 0; }
bool CSteamNetworking::SetP2PSessionSettings(int nChannel, bool bAllowRelay) { return false; }
bool CSteamNetworking::SetP2PSessionDefaultTimeout(int nTimeout) { return false; }
void CSteamNetworking::SetAlwaysRelay(bool bAlwaysRelay) { m_bAlwaysRelay = bAlwaysRelay; }
bool CSteamNetworking::BAllowP2PPacketRelay(bool bAllow) { return false; }