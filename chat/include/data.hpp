#ifndef DATA_HPP_
#define DATA_HPP_

// I / O
#include <iostream>
#include <fstream>

// data
#include <cstring>
#include <vector>

// pid
#include <unistd.h>

// multithreading
#include <semaphore>
#include <mutex>

// file handler
#include "filehandler.hpp"

/*  
    asio

    error:
    Cygwin doesn't work 
    (winsock conflict)
*/
#include "../../third-party/asio-1.24.0/include/asio.hpp"

namespace ucd
{

class Data
{	
private:
	// info
	asio::streambuf info_buffer;
		
	// main data
	asio::streambuf msg_buffer;			
		
	// vector of messages
	std::vector<std::string> msg_buffer_vec;
	
	// synch. to thread
	std::binary_semaphore notify;
	std::mutex mtx;

	// logs
	std::ofstream log_file;
	std::string log_file_name;
	std::string PID;

	// status
	bool socket_is_closed;
	bool disconnected;

public:
	Data() : notify(0)
	{
		socket_is_closed = 0;
		disconnected = 0;

		PID = std::to_string(getpid());
		log_file_name = PID;
		log_file_name += "(PID)logs.txt";
	}

	~Data();			
		
	// get new message
	unsigned int GetMsgBufferSize();
	std::string& GetMsgFromMsgBuffer(unsigned int index);

	// string to streambuf
	asio::streambuf::const_buffers_type SetMessage(std::string);

	// streambuf to string 
	void GetMsg(asio::streambuf&, unsigned int message_size);

	// transfer data to client class
	asio::streambuf::const_buffers_type GetInfoBuffer();	

	// Clear
	void ClearInfoBuf(std::size_t);
	void ClearMsgBuf(std::size_t);

	// wait for getting message
	void Wait();

	// log
	void Log(std::string);

	// Notify
	void NotifyOne();

	// Set Status
	void StatusSocketIsClosed();
	void StatusDisconnected();
	
	// status check
	bool StatusChecking();
};

}

#endif /* DATA_HPP_ */