#include "socket.h" 

int main() {
    try {
        Socket clientSocket;
        clientSocket.connect("127.0.0.1", 12345);

        std::string data_to_send = "Hello, server!";
        clientSocket.send(data_to_send);

        std::string receivedData = clientSocket.recv();
        std::cout << "Received from server: " << receivedData << std::endl;

        clientSocket.closeSocket();
    } catch (const std::exception& ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}