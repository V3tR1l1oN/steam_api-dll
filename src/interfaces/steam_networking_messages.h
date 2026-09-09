#pragma once
#include "../../include/steam/steam_api_goldsrc.h"

class CSteamNetworkingMessages : public ISteamNetworkingMessages {
public:
    CSteamNetworkingMessages() = default;
    virtual ~CSteamNetworkingMessages() = default;

    int ReceiveMessagesOnChannel(int nChannel, int nMaxMessages) override { return 0; }
    int SendMessageToUser(int nSteamId, const void* pData, int cbData, int nSendFlags) override { return 0; }
};