#include <chrono>
#include <cstring>
#include <string>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <iostream>
#include "EchoServer.h"

#define BUFFER_SIZE              1024
#define NEW_CONNECTIONS_DELAY_MS 100
#define DISCONNECT_CMD           "disconnect\r\n"
#define SERVER_STOP_CMD          "stop server\r\n"

void EchoServer::connectionHandler(int masterSock) {
    std::thread clientThread;
    int clientSock;

    for ( ; running; ) {
        if ( clients < maxClients ) {
            clientSock = accept(masterSock, nullptr, nullptr);

            if ( clientSock > 0 ) {
                clientThread = std::thread(&EchoServer::clientHandler, this, clientSock);
                clientThread.detach();

                clients += 1;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(NEW_CONNECTIONS_DELAY_MS));
    }
}

void EchoServer::clientHandler(int clientSock) {
    char* buff {new char[BUFFER_SIZE]};

    for ( bool running {true}; running && this->running; ) {
        bzero(buff, BUFFER_SIZE);

        if ( !read(clientSock, buff, BUFFER_SIZE) ||
             !strcmp(buff, DISCONNECT_CMD) ) {
            running = false;
        } else if ( !strcmp(buff, SERVER_STOP_CMD) ) {
            this->running = false;
        } else {
            write(clientSock, buff, strlen(buff)+1);
        }
    }

    clients -= 1;

    close(clientSock);
    delete[] buff;
}

EchoServer::EchoServer(int port, int maxClients) :
        clients {0},
        running {false},
        maxClients {maxClients},
        port {port} {

    masterSock = socket(AF_INET, SOCK_STREAM, 0);

    if ( masterSock < 0 ) {
        throw SocketCreateException();
    }

    fcntl(masterSock, F_SETFL, fcntl(masterSock, F_GETFL, 0) | O_NONBLOCK);

    bzero((char*) &address, sizeof(address));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(port);

    if ( bind(masterSock, (struct sockaddr*) &address, sizeof(address)) < 0 ) {
        throw SocketBindException();
    }

    if ( listen(masterSock, 0) ) {
        throw SocketListenException();
    }
}

EchoServer::~EchoServer() {
    stop();

    close(masterSock);
}

void EchoServer::start() {
    if ( !running ) {
        running = true;

        std::thread(&EchoServer::connectionHandler, this, masterSock).detach();
    }
}

void EchoServer::stop() {
    if ( running ) {
        running = false;
    }
}

bool EchoServer::isRunning() const {
    return running;
}

int EchoServer::getPort() const {
    return port;
}

int EchoServer::getClients() const {
    return clients;
}
