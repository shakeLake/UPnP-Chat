#ifndef CLIENT_HPP_
#define CLIENT_HPP_

// I / O
#include <iostream>

// data
#include "data.hpp"

// assert
#include <cassert>

// asio
#include "../../third-party/asio-1.24.0/include/asio.hpp"

// std::string
#include <cstring>

namespace ucc
{
    class Client
    {
        private:
            // data
            ucd::Data* info;

            // entry
            //asio::io_context io_c;

            // .resolve
            asio::ip::tcp::resolver rslvr;

            // socket
            asio::ip::tcp::socket sckt;

            // endpoint
            asio::ip::tcp::results_type endpnt;

            asio::error_code error;
        private:
            /* this function sends message to connected ip */
            void SendTo();

            // error handler
            void ErrorHandler(asio::error_code);
        public:
            Client(asio::io_context&, ucd::Data&);
            ~Client() = default;

            /* connects to specific ip address */
            bool Connect();
    };
}

#endif /* CLIENT_HPP_ */