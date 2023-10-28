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

void ClientCore::SendTo(std::string& file_path)
{
	user_data->Log("Sending file");

	fh::FileHandler file_handler_only_info(file_path, user_data, false);

	assert(file_handler_only_info.isGood());

	asio::async_write(sckt, file_handler_only_info.GetFileProperties(), asio::transfer_all(), 
		[&](const asio::error_code& er, std::size_t size)
		{
			if (er)
				user_data->Log(er.message());
			else
			{
				fh::FileHandler file_handler(file_path, user_data, true);

				asio::async_write(sckt, file_handler.GetFile(), asio::transfer_all(),
					[&](const asio::error_code& er, std::size_t size)
					{
						if (er)
							user_data->Log(er.message());
						else
						{
							user_data->Log("File was sent");
						}
					}
				);
			}
		}
	);
}

void ClientCore::SendACK()
{
	user_data->Log("ACK");

	asio::async_write(sckt, ack_message.data(), asio::transfer_all(),
		[this](const asio::error_code& er, std::size_t size)
		{
			if (er)
				user_data->Log(er.message());
			else
			{
				user_data->Log("ACK was sent");
			}
		}
	);
}

void ClientCore::ReceiveFrom(int enum_action)
{
	std::string status_msg = "Receiving: ";
	status_msg += "Flag: ";
	status_msg += std::to_string(file_receive_flag);
	status_msg += " : ";
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

					// if (message_size_buf == "ack*")
					// {
					// 	user_data->Log("ACK was received");

					// 	message_size_buf.clear();
					// 	received_message.consume(size);

					// 	action = info;		
					// 	ReceiveFrom(action);
					// }

					// Get the File
					file_receive_flag = false;
					if (message_size_buf[0] == '#')
						file_receive_flag = true;

					try
					{
						if (file_receive_flag == false)
							message_size = stoi(message_size_buf);
						else
						{
							file_prop = message_size_buf;

							for (unsigned let = 1; let < message_size_buf.size(); ++let)
							{
								if (message_size_buf[let] == '#')
								{
									message_size = stoi(message_size_buf.substr(let + 1, message_size_buf.size() - 1));
									break;
								}
							}
						}
					}
					catch(const std::exception& e)
					{
						user_data->Log(e.what());

						message_size_buf.clear();
						received_message.consume(size);

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

					if (file_receive_flag == false)
						user_data->GetMsg(received_message, message_size);
					else
						fh::FileHandler file(file_prop, received_message, user_data); 

					received_message.consume(size);

					action = info;
					ReceiveFrom(action);
				}
			}
		);
	}
}