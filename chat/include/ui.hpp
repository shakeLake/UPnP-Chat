#ifndef UI_HPP_
#define UI_HPP_

// I / O
#include <iostream>

// std::string
#include <cstring>

namespace ucu
{
    class Ui
    {
        private:
            std::string message;
            std::string ip;
        public:
            Ui() = default;
            ~Ui() = default;

            std::string& EnterMessage();
            std::string& AskIpAddress();
    };
}

#endif /* UI_HPP_ */