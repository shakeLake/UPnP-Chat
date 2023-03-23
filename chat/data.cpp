#include "include/data.hpp"

ucd::Data::Data(std::string& ip)
{
	ip_address = ip;
}

ucd::Data::Data()
{
	ip_address = "default";
}

asio::streambuf::const_buffers_type ucd::Data::SetMessage(std::string& msg)
{
    // ip ...
    full_message += ip_address;
    full_message += ' ';

    // ... text
    full_message += msg;
    full_message += '\n';

    // save message to streambuffer
    std::ostream os_msg(&msg_buffer);
    os_msg << full_message;

    return msg_buffer.data();
}

void ucd::Data::GetMessage(asio::strambuf str)
{
	std::ostringstream os;
	os << str;
	
	msg_buffer.push_back(os.str());
}

unsigned int GetMsgBufferSize()
{
	return msg_buffer.size();
}

std::string& GetMsgFromMsgBuffer(unsigned int index)
{
	return msg_buffer[index];
}

ucd::Data::~Data()
{
    msg_buffer.consume( msg_buffer.size() );
}
