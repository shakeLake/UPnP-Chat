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

void ucs::Server::SendStatus(bool received_or_error, bool info_or_msg)
{
	if (received_or_error)
	{
		if (info_or_msg)
		{
			std::cout << "status: received info" << std::endl;

			asio::async_write(sckt, received_info_buf.data(), asio::transfer_all(), 
				[this](const asio::error_code& e, std::size_t size)
				{
					if (e)
					{
						std::cerr << "Sendig status: ";
						std::cerr << e.message() << std::endl;	
					}
				}
			);
		}
		else
		{
			std::cout << "status: received msg" << std::endl;

			asio::async_write(sckt, received_msg_buf.data(), asio::transfer_all(), 
				[this](const asio::error_code& e, std::size_t size)
				{
					if (e)
					{
						std::cerr << "Sendig status: ";
						std::cerr << e.message() << std::endl;	
					}
				}
			);
		}
	}
	else
	{
		std::cout << "status: error" << std::endl;

		asio::async_write(sckt, error_buf.data(), asio::transfer_all(), 
			[this](const asio::error_code& e, std::size_t size)
			{
				if (e)
				{
					std::cerr << "Sendig status: ";
					std::cerr << e.message() << std::endl;	
				}
			}
		);
	}
}

void ucs::Server::SendTo(asio::streambuf::const_buffers_type msg)
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
    			}
			}
		);
	}
}

void ucs::Server::ReceiveFrom(int enum_action)
{
	std::cout << "receiving: " << enum_action << std::endl;

	if (enum_action == 1)
	{
		asio::async_read_until(sckt, received_message, '*', 
			[this](const asio::error_code& e, std::size_t size)
			{
				if (e)
				{
					std::cerr << "Reading error: ";

					std::cerr << e.message() << std::endl;

					SendStatus(false, true);
				
					action = info;
				}
				else
				{
					std::cout << "Bytes received: " << size  << std::endl;

					// if rec* do this if not do this with arg false
					SendStatus(true, true);
			
					std::istream is(&received_message);	
					is >> message_size_buf;

					if (message_size_buf == "er*")
					{
						info_message_status = false;

						action = info;		
						ReceiveFrom(action);
					}
					else if (message_size_buf == "reci*")
					{
						action = message;		
						ReceiveFrom(action);
					}
					else if (message_size_buf == "recm*")
					{
						action = info;		
						ReceiveFrom(action);
					}
					else
					{
						message_size = stoi(message_size_buf);
						message_size_buf.clear();
						received_message.consume(size);

						action = message;
						ReceiveFrom(action);
					}
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

					SendStatus(false, false);

					action = info;
    			}
    			else
    			{
        			std::cout << "Bytes received: " << size  << std::endl;

					SendStatus(true, false);

					user_data->GetMsg(received_message);
					received_message.consume(size);
				
					action = info;
					ReceiveFrom(action);
    			}
			}
		);
	}
}

bool ucs::Server::SocketIsOpen()
{
	return sckt.is_open();
}
