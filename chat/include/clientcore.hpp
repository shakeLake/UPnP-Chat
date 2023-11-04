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
#include "sslinit.hpp"

// std::bind
#include <functional>

class ClientCore
{
protected:
	const bool CLIENT = true;
	const bool SERVER = false;

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
	bool cli_or_srv;

	// ssl
	SSLContext ctx;
	asio::ssl::context sslcontext;

	// socket
	asio::ssl::stream<asio::ip::tcp::socket> sckt;

protected:
	ClientCore(asio::io_context& io_c, ucd::Data* u_d, bool client_or_server)
	:	sslcontext(std::move(ctx(client_or_server))),
		sckt(io_c, sslcontext)	
	{
		cli_or_srv = client_or_server;

		using namespace std::placeholders;

		if (client_or_server == CLIENT)
		{
			sckt.set_verify_mode(asio::ssl::verify_peer);
			sckt.set_verify_callback(std::bind(&SSLContext::VerifyCertificate, ctx, _1, _2));
		}

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

		// sckt.close();
	}

	/* this function receives data */
	void ReceiveFrom(int);

	void Handshake();

public:
	void SendTo(asio::streambuf::const_buffers_type);
	void SendTo(std::string);
	void SendACK();
	
};

#endif /* SEND_RECEIVE_HPP_ */
