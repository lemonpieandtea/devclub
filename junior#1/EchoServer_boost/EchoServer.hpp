#ifndef ECHO_SERVER_HPP
#define ECHO_SERVER_HPP

#include <boost/asio.hpp>
#include <thread>
#include <atomic>

#include "Server.hpp"

class EchoServer {
private:
    boost::asio::io_service ioService;
    std::thread thread;
    short port;
    std::atomic_bool running;

public:
    EchoServer(short port) : port {port}, running {false} {};
    ~EchoServer() { stop(); };

    void start();
    void stop();

    bool isRunning() const { return running; };
    short getPort() const { return port; };
};

#endif
