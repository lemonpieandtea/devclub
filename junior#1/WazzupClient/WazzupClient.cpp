#include <chrono>
#include <iostream>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "WazzupClient.h"

#define BUFFER_SIZE 1024
#define MESSAGE "Wazzup!\r\n"

void WazzupClient::connectionHandler() {
    char* buff {new char[BUFFER_SIZE]};

    if ( connect(sock, (struct sockaddr*) &client, sizeof(client)) < 0 ) {
        delete[] buff;

        throw SocketConnectException();
    }

    send(sock, MESSAGE, strlen(MESSAGE), 0);

    for ( ; running; ) {
        bzero(buff, BUFFER_SIZE);

        if ( recv(sock, buff, BUFFER_SIZE-1, 0) > 0 ) {
            std::cout << buff;
        } else {
            running = false;
        }
    }

    close(sock);
    delete[] buff;
}

WazzupClient::WazzupClient(IPv4Address address, int port) :
        running {false},
        address {address},
        port {port} {

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if ( sock < 0 ) {
        throw SocketCreateException();
    }

    bzero((char*) &client, sizeof(client));

    client.sin_family = AF_INET;
    client.sin_addr.s_addr = htonl(address.toInt());
    client.sin_port = htons(port);
}

WazzupClient::~WazzupClient() {
    stop();
}

void WazzupClient::start() {
    if ( !running ) {
        running = true;

        std::thread(&WazzupClient::connectionHandler, this).detach();
    }
}

void WazzupClient::stop() {
    if ( running ) {
        running = false;
    }
}

bool WazzupClient::isRunning() const {
    return running;
}

IPv4Address WazzupClient::getAddress() const {
    return address;
}

int WazzupClient::getPort() const {
    return port;
}
