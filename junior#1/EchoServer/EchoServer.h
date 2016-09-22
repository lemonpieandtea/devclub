#ifndef ECHO_SERVER_H
#define ECHO_SERVER_H

#include <netinet/in.h>
#include <thread>
#include <atomic>

#define DEFAULT_PORT     12345
#define DEFAULT_CLIENTS  32

class EchoServer {
    private:
        std::thread connectionThread;
        sockaddr_in address;
        std::atomic_int clients;
        std::atomic_bool running;
        int maxClients;
        int masterSock;
        int port;

        void connectionHandler(int masterSock);
        void clientHandler(int clientSock);

    public:
        static const int defaultPort {DEFAULT_PORT};

        EchoServer(int port = DEFAULT_PORT, int maxClients = DEFAULT_CLIENTS);
        ~EchoServer();

        void start();
        void stop();

        bool isRunning() const;
        int getPort() const;
        int getClients() const;
};

class SocketCreateException {};
class SocketBindException {};
class SocketListenException {};
class SocketAcceptException {};

#endif // ECHO_SERVER_H
