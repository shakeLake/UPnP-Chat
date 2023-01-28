#include "include/ui.hpp"

ucu::Ui::Ui(std::string* usrname, std::string* ipaddr)
{
    std::cout << "Connection established" << std::endl;
    std::cout << '\n';
    
    std::cout << "User: " << *usrname;
    std::cout << " | IP: " << *ipaddr << std::endl;
    std::cout << '\n';
}

std::string* ucu::Ui::EnterMessage()
{
    std::cout << "Enter message: " << std::endl;

    std::getline(std::cin, *message);

    return message;
}

ucu::Ui::~Ui()
{
    delete message;
}