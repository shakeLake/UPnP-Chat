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

void ucc::Client::SendStatus(bool received_or_error)
{
	if (received_or_error)
	{
		std::cout << "received" << std::endl;

		asio::write(sckt, received_buf.data(), asio::transfer_all(), error);

		if (error)
		{
			std::cerr << "Sendig status: ";
			std::cerr << error.message() << std::endl;	
		}
	}
	else
	{
		std::cout << "error" << std::endl;

		asio::write(sckt, error_buf.data(), asio::transfer_all(), error);

		if (error)
		{
			std::cerr << "Sendig status: ";
			std::cerr << error.message() << std::endl;	
		}
	}
}

void ucc::Client::SendTo(asio::streambuf::const_buffers_type msg)
{
	std::cout << "sending" << std::endl;

    asio::async_write(sckt, info_buffer.data(), asio::transfer_all(), 
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
				
				action = status;
    		}
		}
	);

	ReceiveFrom(action);

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
				
				action = status;
    		}
		}
	);

	ReceiveFrom(action);
}

void ucc::Client::ReceiveFrom(int action)
{
	std::cout << "receiving" << std::endl;

	if (action == 1)
	{
    	asio::async_read_until(sckt, received_message, '\n', 
			[this](const asio::error_code& e, std::size_t size)
			{
    			if (e)
    			{
        			std::cerr << "Reading error: ";
        			std::cerr << e.message() << std::endl;

					SendStatus(false)
    			}
    			else
    			{
        			std::cout << "Bytes received: " << size  << std::endl;
					
					SendStatus(true)
    			}
			}
		);
	}	
	else if (action == 0)
	{	
    	asio::async_read(sckt, received_message, asio::transfer_all(), 
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
	else
	{
    	asio::async_read(sckt, received_message, asio::transfer_all(), 
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
    			}
			}
		);
	}
}

bool ucc::Client::SocketIsOpen()
{
	return sckt.is_open();
}
