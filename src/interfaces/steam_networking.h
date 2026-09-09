#pragma once
#include "../../include/steam/steam_api_goldsrc.h"
#include <map>
#include <queue>
#include <mutex>

struct P2PPacket {
    CSteamID sender;
    std::vector<uint8_t> data;
    int channel;
};

class CSteamNetworking : public ISteamNetworking {
public:
    CSteamNetworking();
    virtual ~CSteamNetworking() = default;

    // ISteamNetworking implementation
    bool SendP2PPacket(CSteamID steamIDRemote, const void* pData, uint32 cubData, int nSendFlags, int nChannel) override;
    bool IsP2PPacketAvailable(uint32* pcubDataSize, int nChannel) override;
    bool ReadP2PPacket(void* pDest, uint32 cubDest, uint32* pcubMsgSize, CSteamID* psteamIDRemote, int nChannel) override;
    bool AcceptP2PSessionWithUser(CSteamID steamIDRemote) override;
    bool CloseP2PSessionWithUser(CSteamID steamIDRemote) override;
    bool CloseP2PChannelWithUser(CSteamID steamIDRemote, int nChannel) override;
    SNetListenSocket_t CreateP2PListenSocket(int nSteamConnectPort, int nOptions, int nUserData) override;
    SNetSocket_t CreateP2PConnectionSocket(CSteamID steamIDTarget, int nSteamPort, int nOptions, int nUserData) override;
    SNetSocket_t ConnectP2P(const char* pszSteamID, int nSteamConnectPort, int nOptions, int nUserData) override;
    bool DestroySocket(SNetSocket_t hSocket, bool bNotifyRemote) override;
    bool DestroyListenSocket(SNetListenSocket_t hSocket, bool bNotifyRemote) override;
    bool SendDataOnSocket(SNetSocket_t hSocket, const void* pData, uint32 cubData, bool bReliable) override;
    bool IsDataAvailableOnSocket(SNetSocket_t hSocket, uint32* pcubDataSize) override;
    bool RetrieveDataFromSocket(SNetSocket_t hSocket, void* pDest, uint32 cubDest, uint32* pcubMsgSize) override;
    bool IsListening(SNetListenSocket_t hSocket) override;
    SNetSocket_t GetP2PSessionConnectionInfo(CSteamID steamIDRemote, int* pi_snaux, int* pi_rfcong, int* pi_sdsend, uint64* pulTimeout) override;
    int GetP2PSessionState(CSteamID steamIDRemote, void* pConnectionState) override;
    bool SetP2PSessionSettings(int nChannel, bool bAllowRelay) override;
    bool SetP2PSessionDefaultTimeout(int nTimeout) override;
    void SetAlwaysRelay(bool bAlwaysRelay) override;
    bool BAllowP2PPacketRelay(bool bAllow) override;

private:
    std::map<CSteamID, std::queue<P2PPacket>> m_incomingPackets;
    std::mutex m_mutex;
    bool m_bAlwaysRelay;
};