#pragma once
#include "udp_socket.h"
#include <map>
#include <queue>
#include <mutex>
#include <thread>
#include <atomic>
#include <vector>

struct P2PPacket {
    CSteamID sender;
    std::vector<uint8_t> data;
    int channel;
    uint32_t sequence;
};

class P2PManager {
public:
    static P2PManager& Instance();

    bool Init(int port = 0);
    void Shutdown();

    bool SendPacket(CSteamID target, const void* data, uint32_t size, int channel);
    bool ReadPacket(void* dest, uint32_t* size, CSteamID* sender, int channel, uint32_t maxSize);

    void SetLocalSteamID(CSteamID id) { m_localID = id; }
    CSteamID GetLocalSteamID() const { return m_localID; }

private:
    P2PManager();
    ~P2PManager();

    void ReceiveThread();

    UDPSocket m_socket;
    std::thread m_thread;
    std::atomic<bool> m_running;

    CSteamID m_localID;

    std::map<CSteamID, std::queue<P2PPacket>> m_incoming;
    std::mutex m_mutex;

    uint32_t m_nextSequence;
};