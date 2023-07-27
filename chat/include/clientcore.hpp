#ifndef SEND_RECEIVE_HPP_
#define SEND_RECEIVE_HPP_

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

namespace CCore
{
class ClientCore
{
protected:
	// buffer
	asio::streambuf received_message;	

	// data
	ucd::Data* user_data;

	// socket
	asio::ip::tcp::socket sckt;

protected:
	ClientCore(asio::io_context& io_c, ucd::Data* u_d) : sckt(io_c)
	{
		user_data = u_d;		
	}

	~ClientCore()
	{
		user_data->Log("Client Core destructor");

		user_data->StatusSocketIsClosed();
	
		// data checking reset
		user_data->NotifyOne();

		sckt.close();
	}

	/* this function receives data */
	void ReceiveFrom();

public:
	/* this function sends message to connected ip */
	void SendTo(asio::streambuf::const_buffers_type);
};
}

#endif /* SEND_RECEIVE_HPP_ */