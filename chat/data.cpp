#include "include/data.hpp"

Data::Data(std::string& ip)
{
	ip_address = ip;
}

void SetMessage(std::string& msg)
{
	message = msg
}

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

ucd::Data::~Data()
{
    message.consume( message.size() );
}
