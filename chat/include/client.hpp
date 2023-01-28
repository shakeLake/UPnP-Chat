#ifndef CLIENT_HPP_
#define CLIENT_HPP_

// I / O
#include <iostream>

namespace ucc
{
    class Client
    {
        private:
            asio::io_context io_c;

            asio::ip::tcp::resolver rslvr;

            asio::ip::tcp::socket sckt;
        private:
            /* this function sends message to connected ip */
            void SendTo();
        public:
            Client();
            ~Client();

            /* connects to specific ip address */
            void Connect();
    };
}

#endif /* CLIENT_HPP_ */