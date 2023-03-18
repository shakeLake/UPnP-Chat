#include "include/client.hpp"

void ucc::Client::Connect()
{
    asio::async_connect(sckt, endpnt, 
        [this](const asio::error_code& ec, const asio::ip::tcp::endpoint& next)
        {
            if (ec)
            {
                std::cerr << ec.message() << std::endl;
		
				status = false;
            }
            else
            {
                std::cout << "Connecting to: " << next << std::endl;
				
				status = "true";

				ReceiveFrom();
            }
        }
    ); 
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
				
				// take data here
				received_message.consume(size);

				ReceiveFrom();
    		}
		}
	);
}
