#ifndef CLIENT_HPP_
#define CLIENT_HPP_

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

namespace ucc
{
    class Client
    {
    private:
    	// .resolve
        asio::ip::tcp::resolver rslvr;

        // socket
        asio::ip::tcp::socket sckt;

        // endpoint
        asio::ip::tcp::resolver::results_type endpnt;
			
		// error code			
        asio::error_code error;
			
		// buffer
		asio::streambuf received_message;	

		// data
		ucd::Data* user_data;

		// status buffers
		asio::streambuf received_buf;
		asio::streambuf error_buf;

		// actions
		enum message_info_status_action
		{
			message, info, status
		} action;
		std::string status_message;

	public:
		// connection status
		bool status;

	private:
    	/* connects to specific ip address */
		void Connect();

		/* this function receives data */
		void ReceiveFrom();

		/* sends status */
		void SendStatus(bool);

	public:
    	Client(asio::io_context& io_c, std::string& ip, std::string& port, ucd::Data* u_d) : rslvr(io_c), sckt(io_c)
        {				
        	endpnt = rslvr.resolve(ip, port, error);

            if (error)
           	{
            	std::cerr << "Error: ";
                std::cerr << error.message() << std::endl;
            }

			action = status;
		
			std::ostream os_temp1(&received_buf);
			os_temp << "rec*";
			
			std::ostream os_temp2(&error_buf);
			os_temp << "er*";	 

			user_data = u_d;		

            Connect();
		}

        ~Client() = default;

        /* this function sends message to connected ip */
        void SendTo(asio::streambuf::const_buffers_type);

		// return socket.is_open()
		bool SocketIsOpen();

    };
}

#endif /* CLIENT_HPP_ */
