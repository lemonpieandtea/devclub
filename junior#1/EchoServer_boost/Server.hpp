#ifndef SERVER_HPP
#define SERVER_HPP

#include <boost/asio.hpp>

#include "Session.hpp"

using boost::asio::ip::tcp;

class Server {
private:
    tcp::acceptor acceptor;
    tcp::socket socket;

    void doAccept();

public:
    Server(boost::asio::io_service& ioService, short port);
};

#endif
