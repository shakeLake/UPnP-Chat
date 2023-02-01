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
            std::string ipaddr;
        protected:
            User(std::string);
            ~User() = default;

            std::string GetIpAddr();
            void SetIpAddr(std::string*);
    };

    class Message
    {
        protected:
            std::string msg;
        protected:
            Message() = default;
            ~Message() = default;
            
            // ucu::Ui sets message
            void SetMessage(std::string*);

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
            Data(std::string ipaddr) : User(ipaddr)
            {
                /* 
                    "Useless information..."
                    "Who knows but mb this constructor won't be empty in the future :|"
                */
            }

            Data()
            {
            }

            ~Data() = default;
            
            // creates full message form
            asio::streambuf::const_buffers_type Construction();

    };
}

#endif /* DATA_HPP_ */