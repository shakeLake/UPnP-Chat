#include "include/data.hpp"

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

void ucd::Data::GetMsg(asio::streambuf& str)
{
	std::istream is(&str);
	is >> vec_buf;
	
	msg_buffer_vec.push_back(vec_buf);
	vec_buf.clear();
}

unsigned int ucd::Data::GetMsgBufferSize()
{
	return msg_buffer_vec.size();
}

std::string& ucd::Data::GetMsgFromMsgBuffer(unsigned int index)
{
	return msg_buffer_vec[index];
}

ucd::Data::~Data()
{
    msg_buffer.consume( msg_buffer.size() );
}
