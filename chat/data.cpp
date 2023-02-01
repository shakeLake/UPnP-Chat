#include "include/data.hpp"

// USER class

ucd::User::User(std::string ip)
{
    ipaddr = ip;
}

std::string ucd::User::GetIpAddr()
{
    return ipaddr;
}

void ucd::User::SetIpAddr(std::string* ip)
{
    ipaddr = *ip;
}

// MESSAGE class

void ucd::Message::SetMessage(std::string* message)
{
    msg = *message;
}

std::string ucd::Message::GetMessage()
{
    return msg;
}

// DATA class

asio::streambuf::const_buffers_type ucd::Data::Construction()
{
    // ip ...
    full_message += ipaddr;
    full_message += ' ';

    // ... text
    full_message += msg;
    full_message += '\n';

    // save message to streambuffer
    std::ostream os_msg(&message);
    os_msg << full_message;

    return message.data();
}