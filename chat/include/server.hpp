#ifndef SERVER_HPP_
#define SERVER_HPP_

// I / O
#include <iostream>

// assert
#include <cassert>

// asio
#include "../../third-party/asio-1.24.0/include/asio.hpp"

// std::string
#include <cstring>

// data
#include "data.hpp"

namespace ucs
{
    class Server
    {
    private:
    	// socket
        asio::ip::tcp::socket sckt;

        asio::error_code error;

        asio::ip::tcp::endpoint endpnt;
        asio::ip::tcp::acceptor accptr;

		// buffer
		asio::streambuf received_message;	

		// data
		ucd::Data* user_data;
		unsigned int message_size;
		std::string message_size_buf;

		// status buffers
		asio::streambuf received_buf;
		asio::streambuf error_buf;
		std::string status_buf;
		bool info_message_status;
		
		// actions
		enum message_info_status_action
		{
			message, info, status
		} action;

		std::string status_message;

	public:
		// connection status
		bool connection_status;
			
	private:		
		/* listen connection */
       	void Listening();

		/* receive data */	
        void ReceiveFrom(int);
		
		/* sends status */
		void SendStatus(bool);

    public:
    	Server(asio::io_context& io_c, std::string& port, ucd::Data* u_d) : sckt(io_c), endpnt(asio::ip::tcp::v4(), stoi(port)), accptr(io_c, endpnt)
        {
			action = info;

			user_data = u_d;	
		
			std::ostream os_temp1(&received_buf);
			os_temp1 << "rec*";
			
			std::ostream os_temp2(&error_buf);
			os_temp2 << "er*";	 

            Listening();
        }             
            
        ~Server() = default;

		/* send data */
		bool SendTo(asio::streambuf::const_buffers_type);

		// return socket.is_open()
		bool SocketIsOpen();
    };
}

#endif /* SERVER_HPP */
