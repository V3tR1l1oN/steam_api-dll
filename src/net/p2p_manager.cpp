#include "p2p_manager.h"
#include <cstring>

P2PManager& P2PManager::Instance() {
    static P2PManager instance;
    return instance;
}

P2PManager::P2PManager() : m_running(false), m_nextSequence(0) {}

P2PManager::~P2PManager() {
    Shutdown();
}

bool P2PManager::Init(int port) {
    if (m_running) return true;

    if (!m_socket.Init(port)) return false;

    m_running = true;
    m_thread = std::thread(&P2PManager::ReceiveThread, this);
    return true;
}

void P2PManager::Shutdown() {
    m_running = false;
    if (m_thread.joinable()) {
        m_thread.join();
    }
    m_socket.Shutdown();
}

void P2PManager::ReceiveThread() {
    while (m_running) {
        std::vector<uint8_t> data;
        std::string addr;
        int port;
        if (m_socket.ReceiveFrom(data, addr, port, 100)) {
            // Здесь должна быть десериализация пакета и добавление в очередь
            // Для простоты пока пропускаем
        }
    }
}

bool P2PManager::SendPacket(CSteamID target, const void* data, uint32_t size, int channel) {
    if (!m_running) return false;

    // В реальной реализации нужно сериализовать пакет и отправить через UDP
    // Пока просто эмулируем отправку в локальную очередь
    std::lock_guard<std::mutex> lock(m_mutex);
    P2PPacket packet;
    packet.sender = m_localID;
    packet.data.resize(size);
    memcpy(packet.data.data(), data, size);
    packet.channel = channel;
    packet.sequence = m_nextSequence++;
    m_incoming[target].push(packet);
    return true;
}

bool P2PManager::ReadPacket(void* dest, uint32_t* size, CSteamID* sender, int channel, uint32_t maxSize) {
    std::lock_guard<std::mutex> lock(m_mutex);
    for (auto& pair : m_incoming) {
        auto& queue = pair.second;
        if (!queue.empty()) {
            auto& packet = queue.front();
            if (channel == -1 || packet.channel == channel) {
                uint32_t copySize = std::min(maxSize, (uint32_t)packet.data.size());
                memcpy(dest, packet.data.data(), copySize);
                if (size) *size = copySize;
                if (sender) *sender = packet.sender;
                queue.pop();
                return true;
            }
        }
    }
    return false;
}