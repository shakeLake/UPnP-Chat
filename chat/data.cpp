#include "include/data.hpp"

asio::streambuf::const_buffers_type ucd::Data::SetMessage(std::string& msg)
{
	msg_size = std::to_string(msg.size());
	msg_size += '*';	

    message += msg;

    // saves info about message to streambuffer
    std::ostream os_info(&info_buffer);
    os_info << msg_size;

    // saves message to streambuffer
    std::ostream os_msg(&msg_buffer);
    os_msg << message;

    return msg_buffer.data();
}

void ucd::Data::GetMsg(asio::streambuf& str)
{
	std::istream is(&str);
	is >> vec_buf;
	
	std::cout << "Message: " << vec_buf << std::endl;

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

asio::streambuf::const_buffers_type ucd::Data::GetInfoBuffer()
{
	return info_buffer.data();
}

ucd::Data::~Data()
{
    msg_buffer.consume( msg_buffer.size() );
}

