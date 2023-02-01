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
            std::string* message = new std::string;

            std::string* ip = new std::string;
        public:
            Ui() = default;
            ~Ui();

            std::string* EnterMessage();
            std::string* AskIpAddress();
    };
}

#endif /* UI_HPP_ */