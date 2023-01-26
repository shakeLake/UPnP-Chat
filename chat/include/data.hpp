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
            std::string name;
            std::string ipaddr;
        public:
            User(std::string, std::string);
            ~User() = default;

            std::string GetUsername();
            std::string GetIpaddr();
    };

    class Message
    {
        protected:
            std::string msg;
        public:
            Message() = default;
            ~Message() = default;
            
            // cin.getline()
            void SetMessage();

            // just returns "msg" 
            std::string GetMessage();
    };

    class Data : public User, public Message
    {
        private:
            // username + ipaddr + msg
            std::string full_message;

            asio::streambuf message;
        public:
            Data(std::string username, std::string ipaddr) : User(username, ipaddr)
            {
                /* 
                    "Useless information..."
                    "Who knows but mb this constructor won't be empty in the future :|"
                */
            }

            ~Data() = default;
            
            // creates full message form
            asio::streambuf::const_buffers_type Construction();
    };
}

#endif /* DATA_HPP_ */