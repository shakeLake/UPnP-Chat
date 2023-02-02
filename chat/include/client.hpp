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
            // .resolve
            asio::ip::tcp::resolver rslvr;

            // socket
            asio::ip::tcp::socket sckt;

            // endpoint
            asio::ip::tcp::resolver::results_type endpnt;

            asio::error_code error;
        private:
            /* this function sends message to connected ip */
            void SendTo();
        public:
            Client(asio::io_context& io_c, std::string& ip, const char* port) : rslvr(io_c), sckt(io_c)
            {
                endpnt = rslvr.resolve(ip, port, error);

                if (error)
                {
                    std::cerr << "Error: ";
                    std::cerr << error.message() << std::endl;
                    assert(error);
                }
            }

            ~Client() = default;

            /* connects to specific ip address */
            bool Connect();
    };
}

#endif /* CLIENT_HPP_ */