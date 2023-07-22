#ifndef SOCKET_H
#define SOCKET_H

#include <iostream>
#include <string>

#ifdef _WIN32
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif

class Socket {
public:
    Socket();
    ~Socket();

    void bind(const std::string& address, int port);
    void listen(int backlog = 5);
    void connect(const std::string& address, int port);
    Socket accept();
    void send(const std::string& data);
    std::string recv(size_t bufferSize = 4096);
    void closeSocket();
    void shutdown();

private:
    void initialize();

private:
    int sockfd;
};

#endif // SOCKET_H