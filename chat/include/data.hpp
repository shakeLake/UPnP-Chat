#ifndef DATA_HPP_
#define DATA_HPP_

// DEBUG or RELEASE
#include "../../config.hpp"

// I / O
#include <iostream>
#include <fstream>

// data
#include <cstring>
#include <vector>

// multithreading
#include <condition_variable>
#include <mutex>

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
		std::string msg_size;
		asio::streambuf info_buffer;
			
		// main data
		std::string message;
		asio::streambuf msg_buffer;			
			
		// vector of messages
		std::string vec_buf;
		std::vector<std::string> msg_buffer_vec;
		
		// notifying
		std::mutex mx;
		std::condition_variable cv;

		// logs
		std::ofstream log_file;

	public:
		Data() = default;
		~Data();			
			
		// get new message
		unsigned int GetMsgBufferSize();
		std::string& GetMsgFromMsgBuffer(unsigned int index);
	
		// string to streambuf
		asio::streambuf::const_buffers_type SetMessage(std::string&);

		// streambuf to string 
		void GetMsg(asio::streambuf&);

		// transfer data to client class
		asio::streambuf::const_buffers_type GetInfoBuffer();	

		// Clear
		void ClearInfoBuf(std::size_t);
		void ClearMsgBuf(std::size_t);

		// wait for getting message
		void Wait();

		// log
		void Log(std::string);
	};
}

#endif /* DATA_HPP_ */
