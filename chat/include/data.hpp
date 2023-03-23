#ifndef DATA_HPP_
#define DATA_HPP_

// DEBUG or RELEASE
#include "../../config.hpp"

// I / O
#include <iostream>

// data
#include <cstring>
#include <vector>

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
		// data
		std::string ip_address;
		std::string message;
			
		// temp memory
		std::string full_message;		
		asio::streambuf msg_buffer;			
			
		// vector of messages
		std::string vec_buf;
		std::vector<std::string> msg_buffer_vec;

	public:
		Data();
		~Data();			
			
		// get new message
		unsigned int GetMsgBufferSize();
		std::string& GetMsgFromMsgBuffer(unsigned int index);
	
		// string to streambuf
		asio::streambuf::const_buffers_type SetMessage(std::string&);

		// streambuf to string 
		void GetMessage(asio::streambuf);
	};
}

#endif /* DATA_HPP_ */
