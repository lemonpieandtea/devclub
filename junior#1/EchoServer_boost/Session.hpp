#ifndef SESSION_HPP
#define SESSION_HPP

#include <memory>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
private:
    tcp::socket socket;
    enum { maxLength = 1024 };
    char data[maxLength];

    void doRead();
    void doWrite(std::size_t length);
    void readCmd(char* data);

public:
    Session(tcp::socket socket) : socket {std::move(socket)} {}

    void start() { doRead(); }
};

#endif
