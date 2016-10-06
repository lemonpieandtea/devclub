#include <iostream>

#include "WazzupClient.hpp"

const char* wazzupMsg {"Wazzup!\n"};

void WazzupClient::sessionHandler() {
    try {
        boost::asio::io_service ioService;

        tcp::socket socket(ioService);
        tcp::resolver resolver(ioService);
        boost::asio::connect(socket, resolver.resolve({address, port}));

        boost::asio::write(socket, boost::asio::buffer(wazzupMsg, std::strlen(wazzupMsg)));

        try {
            for ( ; running;) {
                boost::asio::streambuf response;

                boost::asio::read_until(socket, response, "\n");

                std::cout << &response;
            }
        } catch (std::exception& e) {
            std::cerr << "Server read error\n";

            throw;
        }
    } catch (boost::system::system_error const& e) {
        running = false;
    }
}

void WazzupClient::start() {
    if ( !running ) {
        running = true;

        std::thread(&WazzupClient::sessionHandler, this).detach();
    }
}

void WazzupClient::stop() {
    if ( running ) {
        running = false;
    }
}
