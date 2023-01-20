#include "include/data.hpp"

// USER class
User::User(std::string username, std::string ip)
{
    name = username;
    ip = ipaddr;
}

// MESSAGE class

void Message::setMessage()
{
    std::cout << "Enter message: " << std::endl;
    std::std::getline(std::cin, msg);
}

std::string Message::getMessage()
{
    return msg;
}

// DATA class
void Data::construction()
{

}