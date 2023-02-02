#ifndef DATA_HPP_
#define DATA_HPP_

// DEBUG or RELEASE
#include "../../config.hpp"

// I / O
#include <iostream>

// std::string
#include <cstring>

/*  
    asio

    error:
    Cygwin doesn't work 
    (winsock conflict)
*/
#include "../../third-party/asio-1.24.0/include/asio.hpp"

namespace ucd
{
    class User
    {
        protected:
            User(std::string);

            User() = default;
            ~User() = default;
        public:
            std::string ipaddr;
        public:
            void SetIpAddr(std::string&);
    };

    class Message
    {
        protected:
            std::string msg;
        protected:
            Message() = default;
            ~Message() = default;
        public:
            // ucu::Ui sets message
            void SetMessage(std::string&);
    };

    class Data : public User, public Message
    {
        private:
            // username + ipaddr + msg
            std::string full_message;

            asio::streambuf message;
        public:
            Data(std::string ipaddr) : User(ipaddr)
            {
                /* 
                    "Useless information..."
                    "Who knows but mb this constructor won't be empty in the future :|"
                */
            }

            Data() = default;
            ~Data() = default;
            
            // creates full message form
            asio::streambuf::const_buffers_type Construction();

    };
}

#endif /* DATA_HPP_ */