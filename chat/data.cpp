#include "include/data.hpp"

asio::streambuf::const_buffers_type ucd::Data::SetMessage(std::string& msg)
{
	Log("Set Message");

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
	Log("Get Message");

	std::istream is(&str);
	std::getline(is, vec_buf);
	
	msg_buffer_vec.push_back(vec_buf);
	vec_buf.clear();

	cv.notify_one();
}

unsigned int ucd::Data::GetMsgBufferSize()
{
	return msg_buffer_vec.size();
}

std::string& ucd::Data::GetMsgFromMsgBuffer(unsigned int index)
{
	Log("Get message from buffer");

	return msg_buffer_vec[index];
}

asio::streambuf::const_buffers_type ucd::Data::GetInfoBuffer()
{
	Log("Get info buffer");

	return info_buffer.data();
}

void ucd::Data::ClearInfoBuf(std::size_t size)
{
	Log("Clear info buffer");

	msg_size.clear();
	info_buffer.consume(size);
}

void ucd::Data::ClearMsgBuf(std::size_t size)
{
	Log("Clear message buffer");

	message.clear();
	msg_buffer.consume(size);
}

void ucd::Data::Wait()
{
	Log("Waiting");

	std::unique_lock<std::mutex> lk(mx);
	cv.wait(lk);

	Log("Waiting finished");
}

void ucd::Data::Log(std::string log_msg)
{
	log_file.open("logs.txt", std::ios::app);
	log_file << log_msg + '\n';
	log_file.close();
}

ucd::Data::~Data()
{
	Log("Data Destructor");

    msg_buffer.consume( msg_buffer.size() );
	info_buffer.consume( info_buffer.size() );
}
