#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/socket.h>
#include <boost/asio.hpp>

using namespace boost::asio;

int main(int argc, char* argv[]) {
    io_service service;

    ip::tcp::acceptor acceptor(service, ip::tcp::endpoint(ip::tcp::v4(), 8001));

    while (true) {
        ip::tcp::socket sock(service);
        acceptor.accept(sock);

        std::string data;
        boost::system::error_code error;
        read(sock, buffer(data), error);

        write(sock, buffer(data), error);
        sock.close();
    }
    return 0;
}
