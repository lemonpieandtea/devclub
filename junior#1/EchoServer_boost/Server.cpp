#include "Server.hpp"

void Server::doAccept() {
    acceptor.async_accept(socket,
        [this](boost::system::error_code errorCode) {
            if ( !errorCode ) {
                std::make_shared<Session>(std::move(socket))->start();
            }

            doAccept();
        });
}

Server::Server(boost::asio::io_service& ioService, short port) :
    acceptor(ioService, tcp::endpoint(tcp::v4(), port)), socket(ioService) { doAccept(); }
