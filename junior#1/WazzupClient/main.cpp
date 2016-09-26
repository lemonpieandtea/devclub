#include <iostream>
#include <thread>
#include <chrono>

#include "WazzupClient.h"
#include "IPv4Address.h"

#define TIMEOUT 30

int main(int argc, char const *argv[]) {
    if ( argc < 3 ) {
        std::cerr << "Usage: " << argv[0] << " <IP> <Port>" << std::endl;

        return -1;
    }

    IPv4Address address {std::string(argv[1])};
    int port {std::stoi(argv[2])};

    try {
        WazzupClient client(address, port);
        std::cout << "Started WazzupClient on host: " << address.toString() << ", port: " << port << std::endl;


        for ( client.start(); client.isRunning(); ) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        std::cout << "Connection closed" << std::endl;
    } catch (...) {
        std::cout << "Something went wrong..." << std::endl;
    }

    return 0;
}
