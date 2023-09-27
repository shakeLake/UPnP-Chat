#include "include/data.hpp"

asio::streambuf::const_buffers_type ucd::Data::SetMessage(std::string msg)
{
	Log("Set Message");

	std::string msg_size;
	msg_size = std::to_string(msg.size());
	msg_size += '*';	

	// saves message info to streambuffer
	std::ostream os_info(&info_buffer);
	os_info << msg_size;

	std::string message(std::move(msg));

    // saves message to streambuffer
    std::ostream os_msg(&msg_buffer);
    os_msg << message;

    return msg_buffer.data();
}

void ucd::Data::GetMsg(asio::streambuf& str, unsigned int message_size)
{
	Log("Get Message");

	std::string vec_buf;
	vec_buf.resize(message_size);

	std::istream is(&str);
	
	for (int i = 0; i < message_size; i++)
		is.get(vec_buf[i]);

	msg_buffer_vec.push_back(std::move(vec_buf));

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

asio::streambuf::const_buffers_type ucd::Data::GetInfoBuffer()
{
	Log("Get info buffer");

	return info_buffer.data();
}

void ucd::Data::ClearInfoBuf(std::size_t size)
{
	Log("Clear info buffer");

	info_buffer.consume(size);
}

void ucd::Data::ClearMsgBuf(std::size_t size)
{
	Log("Clear message buffer");

	msg_buffer.consume(size);
}

void ucd::Data::Wait()
{
	Log("Waiting");

	notify.acquire();

	Log("Waiting finished");
}

void ucd::Data::Log(std::string log_msg)
{	
	std::unique_lock<std::mutex> lck(mtx);

	log_file.open(log_file_name, std::ios::app);
	log_file << "PID: " << PID << ' ' << log_msg + '\n';

	log_file.close();
}

void ucd::Data::NotifyOne()
{
	Log("Release");

	notify.release();
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