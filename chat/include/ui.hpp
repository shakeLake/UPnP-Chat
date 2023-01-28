#ifndef UI_HPP_
#define UI_HPP_

#include <iostream>

namespace ucu
{
    class Ui
    {
        private:
            std::string* message = new std::string;
        public:
            Ui(std::string*, std::string*);
            ~Ui();

            std::string* EnterMessage();
    };
}

#endif /* UI_HPP_ */