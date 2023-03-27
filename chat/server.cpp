#include "include/server.hpp"

void ucs::Server::Listening()
{
    std::cout << "Listening" << std::endl;
    
    accptr.accept(sckt, endpnt, error);
    
    if (error)
    {
        std::cerr << "Acceptor error: ";
        std::cerr << error.message() << std::endl;
		
		connection_status = 0;
    }
	else
	{
		connection_status = 1;		

	    std::string ip = endpnt.address().to_string();

		ReceiveFrom(action);
	}
}

void ucs::Server::SendStatus(bool received_or_error)
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

bool ucs::Server::SendTo(asio::streambuf::const_buffers_type msg)
{
	info_message_status = true;

	std::cout << "sending" << std::endl;

    asio::async_write(sckt, user_data->GetInfoBuffer(), asio::transfer_all(), 
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
				ReceiveFrom(action);
    		}
		}
	);

	if (info_message_status)
	{
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
					ReceiveFrom(action);
    			}
			}
		);
	}
	else
	{
		return false;
	}
	
	return info_message_status == true ? true : false;
}

void ucs::Server::ReceiveFrom(int enum_action)
{
	std::cout << "receiving" << std::endl;

	if (enum_action == 1)
	{
    	asio::async_read_until(sckt, received_message, '*', 
			[this](const asio::error_code& e, std::size_t size)
			{
    			if (e)
    			{
	       			std::cerr << "Reading error: ";

        			std::cerr << e.message() << std::endl;

					SendStatus(false);
					
					action = info;
    			}
    			else
    			{
        			std::cout << "Bytes received: " << size  << std::endl;
				
					std::istream is(&received_message);	
					is >> message_size_buf;
	
					message_size = stoi(message_size_buf);
					message_size_buf.clear();
					
					SendStatus(true);

					action = message;
    			}
			}
		);
	}	
	else if (enum_action == 0)
	{	
    	asio::async_read(sckt, received_message, asio::transfer_exactly(message_size), 
			[this](const asio::error_code& e, std::size_t size)
			{
    			if (e)
    			{
        			std::cerr << "Reading error: ";

        			std::cerr << e.message() << std::endl;

					SendStatus(false);

					action = info;
    			}
    			else
    			{
        			std::cout << "Bytes received: " << size  << std::endl;

					SendStatus(true);
				
					user_data->GetMsg(received_message);
					received_message.consume(size);
					
					action = info;
    			}
			}
		);
	}
	else
	{
    	asio::read_until(sckt, received_message, '*', error);
 
    	if (error)
    	{
       		std::cerr << "Reading error: ";
        	std::cerr << error.message() << std::endl;
	
			action = info;
    	}
		else
		{
			std::istream is(&received_message);	
			is >> status_buf;
				
			std::cout << "Status: " << status_buf << std::endl;

			if (status_buf == "er*")
			{
				action = info;		
				
				info_message_status = false;
			}
		}
	}

	ReceiveFrom(action);
}

bool ucs::Server::SocketIsOpen()
{
	return sckt.is_open();
}
