#ifndef DATA_HPP_
#define DATA_HPP_

// I / O
#include <iostream>

// std::string
#include <cstring>

namespace sL_data
{
    class User
    {
        private:
            std::string name;
            std::string ipaddr;
        public:
            User(std::string, std::string);
            ~User() = default;
    };

    class Message
    {
        private:
            std::string msg;
        public:
            Message() = default;
            ~Message() = default;
            
            // cin.getline()
            void setMessage();

            // just returns "msg" 
            void getMessage();
    };

    class Data : public User, public Message
    {
        public:
            Data(std::string username, std::string ipaddr) : User(username, ipaddr)
            {
                /* 
                    "Useless information..."
                    "Who knows but mb this constructor won't be empty in the future ;)"
                */
            }

            ~Data() = default;
            
            // creates full message form
            void construction();
    };
}

#endif /* DATA_HPP_ */