#include <iostream>
#include <thread>
#include <chrono>

#include "WazzupClient.hpp"

int main(int argc, char* argv[]) {
    if ( argc != 3 ) {
        std::cerr << "Usage: " << argv[0] << "<address> <port>\n";

        return 1;
    }

    WazzupClient wazzupClient(argv[1], argv[2]);

    std::cout << "Starting WazzupClient client on host: " << wazzupClient.getAddress();
    std::cout << ", port: " << wazzupClient.getPort() << "\n";

    for ( wazzupClient.start(); wazzupClient.isRunning(); ) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
