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

// filehandler
#include "filehandler.hpp"

// ssl
#include "sslinitclient.hpp"
// #include "sslinitserver.hpp"

class ClientCore
{
protected:
	// buffer
	asio::streambuf received_message;	

	// data
	unsigned int message_size;
	std::string message_size_buf;
	asio::streambuf ack_message;

	// file data
	bool file_receive_flag;
	std::string file_prop;

	// status buffers
	asio::streambuf error_buf;

	// actions
	enum message_info_status_action
	{
		message, info
	} action;

	// data
	ucd::Data* user_data;

	// socket
	asio::ssl::stream<asio::ip::tcp::socket> sckt;

protected:
	ClientCore(asio::io_context& io_c, ucd::Data* u_d, bool client_or_server) : sckt(io_c, SSLContext(client_or_server)())
	{
		action = info;

		user_data = u_d;		

		std::string ack_msg = "ack*";
		std::ostream os(&ack_message);
		os << ack_msg;
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
	void ReceiveFrom(int);

public:
	void SendTo(asio::streambuf::const_buffers_type);
	void SendTo(std::string);
	void SendACK();
	
};

#endif /* SEND_RECEIVE_HPP_ */
