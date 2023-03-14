#ifndef DATA_HPP_
#define DATA_HPP_

// DEBUG or RELEASE
#include "../../config.hpp"

// I / O
#include <iostream>

// std::string
#include <cstring>

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

		public:
			Data();

			Data(std::string&);
			~Data();			

			asio::streambuf::const_buffers_type SetMessage(std::string&);
	};
}

#endif /* DATA_HPP_ */
