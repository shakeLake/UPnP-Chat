#include "include/ui.hpp"

std::string* ucu::Ui::EnterMessage()
{
    std::cout << "Enter message: " << std::endl;

    std::getline(std::cin, *message);

    return message;
}

std::string* ucu::Ui::AskIpAddress()
{
    std::cout << "Where to connect (ip address): ";

    std::getline(std::cin, *ip);

    return ip;
}

ucu::Ui::~Ui()
{
    delete message;
    delete ip;
}