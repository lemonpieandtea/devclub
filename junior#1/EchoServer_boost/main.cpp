#include <iostream>
#include <thread>
#include <chrono>

#include "EchoServer.hpp"

int main(int argc, char* argv[]) {
    try {
        if (argc != 2) {
            std::cerr << "Usage: " << argv[0] << " <port>\n";

            return 1;
        }

        EchoServer echoServer(std::atoi(argv[1]));

        std::cout << "Starting echo server on host: localhost";
        std::cout << ", port: " << echoServer.getPort() << "\n";

        for ( echoServer.start(); echoServer.isRunning(); ) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
