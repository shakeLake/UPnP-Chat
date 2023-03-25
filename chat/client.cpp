#include "include/client.hpp"

void ucc::Client::Connect()
{
    asio::connect(sckt, endpnt, error);
 
   	if (error)
    {
    	std::cerr << error.message() << std::endl;
		
		status = false;
	}
    else
    {
    	std::cout << "Connected" << std::endl;
				
		status = "true";

		ReceiveFrom();
    }
}

void ucc::Client::SendTo(asio::streambuf::const_buffers_type msg)
{
	std::cout << "sending" << std::endl;

    asio::async_write(sckt, msg, asio::transfer_all(), 
		[this](const asio::error_code& e, std::size_t size)
		{
    		if (e)
    		{
        		std::cerr << "Sending error: ";
        		std::cerr << e.message() << std::endl;
    		}
    		else
    		{
        		std::cout << "Bytes transferred: " << size  << std::endl;
    		}
		}
	);
}

void ucc::Client::ReceiveFrom()
{
	std::cout << "receiving" << std::endl;

    asio::async_read_until(sckt, received_message, '\n', 
		[this](const asio::error_code& e, std::size_t size)
		{
    		if (e)
    		{
        		std::cerr << "Reading error: ";
        		std::cerr << e.message() << std::endl;
    		}
    		else
    		{
        		std::cout << "Bytes received: " << size  << std::endl;
				
				user_data->GetMsg(received_message);
				received_message.consume(size);

				ReceiveFrom();
    		}
		}
	);
}

bool ucc::Client::SocketIsOpen()
{
	return sckt.is_open();
}
