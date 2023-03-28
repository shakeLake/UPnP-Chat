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
		unsigned int message_size;
		std::string message_size_buf;

		// status buffers
		asio::streambuf received_info_buf;
		asio::streambuf received_msg_buf;
		asio::streambuf error_buf;
		bool info_message_status;

		// actions
		enum message_info_status_action
		{
			message, info
		} action;

		std::string status_message;

	public:
		// connection status
		bool connection_status;

	private:
    	/* connects to specific ip address */
		void Connect();

		/* this function receives data */
		void ReceiveFrom(int);

		/* sends status */
		void SendStatus(bool, bool);

	public:
    	Client(asio::io_context& io_c, std::string& ip, std::string& port, ucd::Data* u_d) : rslvr(io_c), sckt(io_c)
        {				
        	endpnt = rslvr.resolve(ip, port, error);

            if (error)
           	{
            	std::cerr << "Error: ";
                std::cerr << error.message() << std::endl;
            }

			action = info;

			std::ostream os_temp1(&received_info_buf);
			os_temp1 << "reci*";
			
			std::ostream os_temp2(&received_msg_buf);
			os_temp2 << "recm*";

			std::ostream os_temp3(&error_buf);
			os_temp3 << "er*";	 

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
