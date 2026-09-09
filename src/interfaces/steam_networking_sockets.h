#pragma once
#include "../../include/steam/steam_api_goldsrc.h"

class CSteamNetworkingSockets : public ISteamNetworkingSockets {
public:
    CSteamNetworkingSockets() = default;
    virtual ~CSteamNetworkingSockets() = default;

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