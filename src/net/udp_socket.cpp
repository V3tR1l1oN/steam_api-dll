#include "udp_socket.h"
#include <cstring>
#include <stdexcept>

UDPSocket::UDPSocket() : m_socket(INVALID_SOCKET), m_port(0), m_initialized(false) {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
}

UDPSocket::~UDPSocket() {
    Shutdown();
    WSACleanup();
}

bool UDPSocket::Init(int port) {
    if (m_initialized) Shutdown();

    m_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (m_socket == INVALID_SOCKET) return false;

    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    if (bind(m_socket, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
        closesocket(m_socket);
        m_socket = INVALID_SOCKET;
        return false;
    }

    // Получаем реальный порт
    sockaddr_in localAddr;
    int len = sizeof(localAddr);
    if (getsockname(m_socket, (sockaddr*)&localAddr, &len) == 0) {
        m_port = ntohs(localAddr.sin_port);
    } else {
        m_port = port;
    }

    m_initialized = true;
    return true;
}

void UDPSocket::Shutdown() {
    if (m_socket != INVALID_SOCKET) {
        closesocket(m_socket);
        m_socket = INVALID_SOCKET;
    }
    m_initialized = false;
    m_port = 0;
}

bool UDPSocket::SendTo(const std::vector<uint8_t>& data, const std::string& addr, int port) {
    if (!m_initialized || data.empty()) return false;

    sockaddr_in destAddr;
    memset(&destAddr, 0, sizeof(destAddr));
    destAddr.sin_family = AF_INET;
    destAddr.sin_port = htons(port);
    inet_pton(AF_INET, addr.c_str(), &destAddr.sin_addr);

    int sent = sendto(m_socket, (const char*)data.data(), (int)data.size(), 0,
                      (sockaddr*)&destAddr, sizeof(destAddr));
    return sent == (int)data.size();
}

bool UDPSocket::ReceiveFrom(std::vector<uint8_t>& data, std::string& addr, int& port, int timeoutMs) {
    if (!m_initialized) return false;

    // Таймаут
    if (timeoutMs > 0) {
        fd_set set;
        FD_ZERO(&set);
        FD_SET(m_socket, &set);
        timeval tv;
        tv.tv_sec = timeoutMs / 1000;
        tv.tv_usec = (timeoutMs % 1000) * 1000;
        if (select(0, &set, nullptr, nullptr, &tv) <= 0) return false;
    }

    char buffer[65536];
    sockaddr_in srcAddr;
    int srcLen = sizeof(srcAddr);
    int recv = recvfrom(m_socket, buffer, sizeof(buffer), 0,
                        (sockaddr*)&srcAddr, &srcLen);
    if (recv <= 0) return false;

    data.assign(buffer, buffer + recv);

    char ipStr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &srcAddr.sin_addr, ipStr, sizeof(ipStr));
    addr = ipStr;
    port = ntohs(srcAddr.sin_port);
    return true;
}