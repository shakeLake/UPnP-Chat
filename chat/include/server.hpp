#ifndef SERVER_HPP_
#define SERVER_HPP_

// I / O
#include <iostream>

// assert
#include ""

namespace ucs
{
    class Server
    {
        private:
            // entry
            asio::io_context io_c;

            // socket
            asio::ip::tcp::socket sckt;

            asio::error_code error;

            asio::ip::tcp::endpoint endpnt;
            asio::ip::tcp::acceptor accptr;
        private:
            // funcs
        public:
            Server(std::string port) : sckt(io_c), endpnt(asio::ip::tcp::v4(), port), accptr(io_c, endpnt)
            {
                /*
                    invisibility
                */
            }             
            
            ~Server() = default;

            void Listening();
    };
}

#endif /* SERVER_HPP */