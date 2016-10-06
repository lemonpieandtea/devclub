#ifndef WAZZUP_CLIENT_HPP
#define WAZZUP_CLIENT_HPP

#include <boost/asio.hpp>
#include <thread>
#include <atomic>
#include <string>

using boost::asio::ip::tcp;

class WazzupClient {
private:
    boost::asio::io_service ioService;
    std::thread thread;
    std::string address;
    std::string port;
    std::atomic_bool running;
    enum { maxLength = 1024 };

    void sessionHandler();

public:
    WazzupClient(const std::string& address, const std::string& port) : address {address}, port {port}, running {false} {};
    ~WazzupClient() {};

    void start();
    void stop();

    bool isRunning() const { return running; };
    const std::string& getAddress() const { return address; };
    const std::string& getPort() const { return port; };
};

#endif
