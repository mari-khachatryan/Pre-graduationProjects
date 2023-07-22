#include "Socket.h"
#include <cstring> 


Socket::Socket() : sockfd(-1) {
    initialize();
}

Socket::~Socket() {
    closeSocket();
}

void Socket::bind(const std::string& address, int port) {
    if (sockfd < 0) {
        throw std::runtime_error("Socket not created!");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

#ifdef _WIN32
    if (inet_pton(AF_INET, address.c_str(), &server_addr.sin_addr) <= 0) {
#else
    if (inet_aton(address.c_str(), &server_addr.sin_addr) == 0) {
#endif
        throw std::runtime_error("Invalid address");
    }

    if (::bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        throw std::runtime_error("Error binding socket: " + std::string(strerror(errno)));
    }
}

void Socket::listen(int backlog) {
    if (sockfd < 0) {
        throw std::runtime_error("Socket not created");
    }

    if (::listen(sockfd, backlog) < 0) {
        throw std::runtime_error("Error listening on socket: " + std::string(strerror(errno)));
    }
}

void Socket::connect(const std::string& address, int port) {
    if (sockfd < 0) {
        throw std::runtime_error("Socket not created");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

#ifdef _WIN32
    if (inet_pton(AF_INET, address.c_str(), &server_addr.sin_addr) <= 0) {
#else
    if (inet_aton(address.c_str(), &server_addr.sin_addr) == 0) {
#endif
        throw std::runtime_error("Invalid address");
    }

    if (::connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        throw std::runtime_error("Error connecting to server: " + std::string(strerror(errno)));
    }
}

Socket Socket::accept() {
    if (sockfd < 0) {
        throw std::runtime_error("Socket not created");
    }

    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int client_sock = ::accept(sockfd, (struct sockaddr*)&client_addr, &addr_len);

    if (client_sock < 0) {
        throw std::runtime_error("Error accepting connection: " + std::string(strerror(errno)));
    }

    Socket client_socket;
    client_socket.sockfd = client_sock;
    return client_socket;
}

void Socket::send(const std::string& data) {
    if (sockfd < 0) {
        throw std::runtime_error("Socket not created");
    }

    ssize_t sent_bytes = ::send(sockfd, data.c_str(), data.size(), 0);
    if (sent_bytes < 0) {
        throw std::runtime_error("Error sending data: " + std::string(strerror(errno)));
    }
}

std::string Socket::recv(size_t bufferSize) {
    if (sockfd < 0) {
        throw std::runtime_error("Socket not created");
    }

    char buffer[bufferSize];
    ssize_t received_bytes = ::recv(sockfd, buffer, bufferSize - 1, 0);
    if (received_bytes < 0) {
        throw std::runtime_error("Error receiving data: " + std::string(strerror(errno)));
    }

    buffer[received_bytes] = '\0';
    return std::string(buffer);
}

void Socket::closeSocket() {
    if (sockfd >= 0) {
#ifdef _WIN32
        closesocket(sockfd);
#else
        close(sockfd);
#endif
        sockfd = -1;
    }
}

void Socket::shutdown() {
    if (sockfd < 0) {
        throw std::runtime_error("Socket not created");
    }

#ifdef _WIN32
    if (::shutdown(sockfd, SD_BOTH) < 0) {
#else
    if (::shutdown(sockfd, SHUT_RDWR) < 0) {
#endif
        throw std::runtime_error("Error shutting down socket: " + std::string(strerror(errno)));
    }
}

void Socket::initialize() {
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        throw std::runtime_error("WSAStartup failed");
    }
#endif

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        throw std::runtime_error("Error creating socket: " + std::string(strerror(errno)));
    }
}
