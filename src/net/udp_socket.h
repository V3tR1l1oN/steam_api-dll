#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <vector>

class UDPSocket {
public:
    UDPSocket();
    ~UDPSocket();

    bool Init(int port = 0);
    void Shutdown();
    bool SendTo(const std::vector<uint8_t>& data, const std::string& addr, int port);
    bool ReceiveFrom(std::vector<uint8_t>& data, std::string& addr, int& port, int timeoutMs = 0);
    int GetPort() const { return m_port; }

private:
    SOCKET m_socket;
    int m_port;
    bool m_initialized;
};