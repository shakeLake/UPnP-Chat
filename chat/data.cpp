#include "include/data.hpp"

// USER class
ucd::User::User(std::string username, std::string ip)
{
    name = username;
    ip = ipaddr;
}

std::string ucd::User::GetUsername()
{
    return name;
}

std::string ucd::User::GetIpaddr()
{
    return ipaddr;
}

// MESSAGE class
void ucd::Message::SetMessage()
{
    std::cout << "Enter message: " << std::endl;
    //std::getline(std::cin, msg);
}

std::string ucd::Message::GetMessage()
{
    return msg;
}

// DATA class
asio::streambuf::const_buffers_type ucd::Data::Construction()
{
    // username ... ...
    full_message += GetUsername();
    full_message += ' ';

    // ... ip ...
    full_message += GetIpaddr();
    full_message += ' ';

    // ... ... text
    full_message += GetMessage();
    full_message += '\n';

    // save message to streambuffer
    std::ostream os_msg(&message);
    os_msg << full_message;

    std::cout << full_message;

    return message.data();
}