#ifndef SERVER_HPP_
#define SERVER_HPP_

// I / O
#include <iostream>

// assert
#include <cassert>

// asio
#include "../../third-party/asio-1.24.0/include/asio.hpp"

// std::string
#include <cstring>

namespace ucs
{
    class Server
    {
        private:
            // socket
            asio::ip::tcp::socket sckt;

            asio::error_code error;

            asio::ip::tcp::endpoint endpnt;
            asio::ip::tcp::acceptor accptr;

            asio::streambuf data;
        public:
            Server(asio::io_context& io_c, const char* port) : sckt(io_c), endpnt(asio::ip::tcp::v4(), atoi(port)), accptr(io_c, endpnt)
            {
                /*
                    invisibility
                */
            }             
            
            ~Server() = default;

            std::string Listening();

            void ReadFrom();
    };
}

#endif /* SERVER_HPP */