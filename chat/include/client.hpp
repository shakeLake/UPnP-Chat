#ifndef CLIENT_HPP_
#define CLIENT_HPP_

// I / O
#include <iostream>

// data
#include "data.hpp"

namespace ucc
{
    class Client
    {
        private:
            // data
            ucd::Data* info;

            asio::io_context io_c;

            // .resolve
            asio::ip::tcp::resolver rslvr;

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
            Client(ucd::Data&);
            ~Client() = default;

            /* connects to specific ip address */
            bool Connect();
    };
}

#endif /* CLIENT_HPP_ */