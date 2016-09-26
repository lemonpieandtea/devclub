#ifndef WAZZUP_CLIENT_H
#define WAZZUP_CLIENT_H

#include <netinet/in.h>
#include <thread>
#include <atomic>

#include "IPv4Address.h"

class WazzupClient {
    private:
        std::thread connection;
        std::atomic_bool running;
        IPv4Address address;
        sockaddr_in client;
        int sock;
        int port;

        void connectionHandler();

    public:
        WazzupClient(IPv4Address address, int port);
        ~WazzupClient();

        void start();
        void stop();

        bool isRunning() const;
        IPv4Address getAddress() const;
        int getPort() const;
};

class SocketCreateException {};
class SocketConnectException {};
class SocketListenException {};
class SocketAcceptException {};

#endif
