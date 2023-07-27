#include "include/data.hpp"

asio::streambuf::const_buffers_type ucd::Data::SetMessage(std::string msg)
{
	Log("Set Message");

    // saves message to streambuffer
    std::ostream os_msg(&msg_buffer);
    os_msg << msg;

    return msg_buffer.data();
}

void ucd::Data::GetMsg(asio::streambuf& str)
{
	Log("Get Message");

	std::string vec_buf;
	vec_buf.resize(str.size());

	std::istream is(&str);
	
	for (int i = 0; i < str.size(); i++)
		is.get(vec_buf[i]);

	msg_buffer_vec.push_back(vec_buf);

	NotifyOne();
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

void ucd::Data::ClearMsgBuf(std::size_t size)
{
	Log("Clear message buffer");

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

void ucd::Data::NotifyOne()
{	
	cv.notify_one();
}

void ucd::Data::StatusSocketIsClosed()
{
	socket_is_closed = 1;
}

void ucd::Data::StatusDisconnected()
{
	disconnected = 1;
}

bool ucd::Data::StatusChecking()
{
	if (socket_is_closed == 1 || disconnected == 1)
		return 0;
	else
		return 1;
}

ucd::Data::~Data()
{
	Log("Data Destructor");

    msg_buffer.consume( msg_buffer.size() );
	info_buffer.consume( info_buffer.size() );
}
