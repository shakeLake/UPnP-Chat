#include "include/server.hpp"

void ucs::Server::Listening()
{
    std::cout << "Listening" << std::endl;
    
    accptr.accept(sckt, endpnt, error);
    
    if (error)
    {
        std::cerr << "Acceptor error: ";
        std::cerr << error.message() << std::endl;
		
		status = 0;
    }
	else
	{
		status = 1;		

	    std::string ip = endpnt.address().to_string();

		ReceiveFrom();
	}
}

void ucs::Server::SendTo(asio::streambuf::const_buffers_type msg)
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

void ucs::Server::ReceiveFrom()
{
	std::cout << "receiving" << std::endl;

    asio::async_read_until(sckt, data, '\n', 
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
				data.consume( size );			
	
				ReceiveFrom();
    		}
		}
	);
}
