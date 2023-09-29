#include "include/clientcore.hpp"

void ClientCore::SendTo(asio::streambuf::const_buffers_type msg)
{
	user_data->Log("Sending");

	asio::async_write(sckt, user_data->GetInfoBuffer(), asio::transfer_all(), 
		[this, msg](const asio::error_code& e, std::size_t size)
		{
			if (e)
			{
				user_data->Log(e.message());
			}
			else
			{
				user_data->ClearInfoBuf(size);
				
				asio::async_write(sckt, msg, asio::transfer_all(), 
					[this](const asio::error_code& e, std::size_t size)
					{
						if (e)
						{
							user_data->Log(e.message());
						}
						else
							user_data->ClearMsgBuf(size);
					}
				);
			}
		}
	);

	user_data->Log("Sending finished");
}

void ClientCore::ReceiveFrom(int enum_action)
{
	std::string status_msg = "Receiving ";
	status_msg += std::to_string(enum_action);
	user_data->Log(status_msg);
	
	if (enum_action)
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
					user_data->Log("Info Received");

					std::istream is(&received_message);	
					is >> message_size_buf;

					try
					{
						message_size = stoi(message_size_buf);
					}
					catch(const std::exception& e)
					{
						user_data->Log(e.what());

						action = info;		
						ReceiveFrom(action);
					}

					message_size_buf.clear();
					received_message.consume(size);

					action = message;
					ReceiveFrom(action);
				}
			}
		);
	}
	else
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
					user_data->Log("Message Received");

					user_data->GetMsg(received_message, message_size);

					received_message.consume(size);

					action = info;
					ReceiveFrom(action);
				}
			}
		);
	}
}