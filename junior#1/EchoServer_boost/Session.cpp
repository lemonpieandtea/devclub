#include <cstring>

#include "Session.hpp"

const char* disconnectCmd {"disconnect\r\n"};
const char* stopServerCmd {"stop server\r\n"};

void Session::doRead() {
    auto self {shared_from_this()};

    socket.async_read_some(boost::asio::buffer(data, maxLength),
        [this, self](boost::system::error_code errorCode, std::size_t length) {
            if ( !errorCode ) {
                readCmd(data);
                doWrite(length);
            }
        });
}

void Session::doWrite(std::size_t length) {
    auto self {shared_from_this()};

    boost::asio::async_write(socket, boost::asio::buffer(data, length),
        [this, self](boost::system::error_code errorCode, std::size_t length) {
            if ( !errorCode ) {
                doRead();
            }
        });
}

void Session::readCmd(char* data) {
    if ( !std::strcmp(data, disconnectCmd) ) {
        socket.close();
    } else if ( !std::strcmp(data, stopServerCmd) ) {
        socket.get_io_service().stop();
    }
}
