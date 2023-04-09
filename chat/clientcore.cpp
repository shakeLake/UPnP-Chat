#include "include/clientcore.hpp"

void ClientCore::SendTo(asio::streambuf::const_buffers_type msg)
{
	user_data->Log("Sending");

	info_message_status = true;

	if (info_message_status)
	{
		asio::async_write(sckt, user_data->GetInfoBuffer(), asio::transfer_all(), 
			[this](const asio::error_code& e, std::size_t size)
			{
				if (e)
				{
					user_data->Log(e.message());
				}
				else
				{
					user_data->ClearInfoBuf(size);
				}
			}
		);
	}

	if (info_message_status)
	{
    	asio::async_write(sckt, msg, asio::transfer_all(), 
			[this](const asio::error_code& e, std::size_t size)
			{
    			if (e)
    			{
					user_data->Log(e.message());
    			}
    			else
    			{
					user_data->ClearMsgBuf(size);
    			}
			}
		);
	}	
}

void ClientCore::ReceiveFrom(int enum_action)
{
	user_data->Log("Receiving");
	
	if (enum_action == 1)
	{
		asio::async_read_until(sckt, received_message, '*', 
			[this](const asio::error_code& e, std::size_t size)
			{
				if (e)
				{
					user_data->Log(e.message());

					received_message.consume(size);
				}
				else
				{
					std::istream is(&received_message);	
					is >> message_size_buf;

					if (message_size_buf == "er*")
					{
						info_message_status = false;

						action = info;		
						ReceiveFrom(action);
					}
					else
					{
						try
						{
							message_size = stoi(message_size_buf);
						}
						catch(const std::exception& e)
						{
							 user_data->Log(e.what());
						}

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
					user_data->Log(e.message());

					received_message.consume(size);
    			}
    			else
    			{
					user_data->GetMsg(received_message, message_size);

					received_message.consume(size);
				
					action = info;
					ReceiveFrom(action);
    			}
			}
		);
	}
}
