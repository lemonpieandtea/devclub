#include "EchoServer.hpp"

void EchoServer::start() {
    if ( !running ) {
        running = true;

        std::thread([this]() {
            try {
                Server server(ioService, port);

                ioService.run();

                running = false;
            } catch (...) {
                running = false;
            }
        }).detach();
    }
}

void EchoServer::stop() {
    if ( running ) {
        running = false;

        ioService.stop();
    }
}
