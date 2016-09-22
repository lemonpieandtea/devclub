#include <iostream>
#include <thread>
#include <chrono>

#include "EchoServer.h"

#define TIMEOUT 30

int main(int argc, char const *argv[]) {
    int port {EchoServer::defaultPort};

    if ( argc == 2 ) {
        port = std::stol(argv[1]);
    }

    EchoServer server(port);
    std::cout << "Started echo server on host: localhost, port: " << server.getPort() << std::endl;


    for ( server.start(); server.isRunning(); ) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Connection closed, restarting for " << TIMEOUT << " seconds" << std::endl;
    server.start();

    std::this_thread::sleep_for(std::chrono::seconds(30));

    std::cout << "Stopping server" << std::endl;
    server.stop();

    std::cout << "Server stopped, exit in 5 seconds" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}
