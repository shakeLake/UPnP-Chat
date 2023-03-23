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

        asio::streambuf data;

		// data
		ucd::Data* user_data;
		
	public:
		// connection status
		bool status;
			
	private:		
		/* listen connection */
       	void Listening();
	
    public:
    	Server(asio::io_context& io_c, std::string& port, ucd::Data* u_d) : sckt(io_c), endpnt(asio::ip::tcp::v4(), stoi(port)), accptr(io_c, endpnt)
        {
			user_data = u_d;	
		
            Listening();
        }             
            
        ~Server() = default;

		/* send data */
		void SendTo(asio::streambuf::const_buffers_type);
	
		/* receive data */	
        void ReceiveFrom();
    };
}

#endif /* SERVER_HPP */
