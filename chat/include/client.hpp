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

	public:
		// connection status
		bool status;

	private:
    	/* connects to specific ip address */
		void Connect();

		/* this function receives data */
		void ReceiveFrom();

	public:
    	Client(asio::io_context& io_c, std::string& ip, std::string& port, ucd::Data* u_d) : rslvr(io_c), sckt(io_c)
        {
			user_data = u_d;		
	
        	endpnt = rslvr.resolve(ip, port, error);

            if (error)
           	{
            	std::cerr << "Error: ";
                std::cerr << error.message() << std::endl;
            }

            Connect();
		}

        ~Client() = default;

        /* this function sends message to connected ip */
        void SendTo(asio::streambuf::const_buffers_type);
    };
}

#endif /* CLIENT_HPP_ */
