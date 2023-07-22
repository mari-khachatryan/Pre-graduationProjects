#include "socket.h"

int main() {
    try {
        Socket serverSocket;
        serverSocket.bind("0.0.0.0", 12345);
        serverSocket.listen();

        std::cout << "Server is listening for incoming connections..." << std::endl;

        Socket clientSocket = serverSocket.accept();

        std::string receivedData = clientSocket.recv();
        std::cout << "Received from client: " << receivedData << std::endl;

        std::string response = "Hello, client!";
        clientSocket.send(response);

        clientSocket.closeSocket();

        serverSocket.closeSocket();
    } catch (const std::exception& ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}