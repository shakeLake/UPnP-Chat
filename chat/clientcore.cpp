#include "include/clientcore.hpp"

void CCore::ClientCore::SendTo(asio::streambuf::const_buffers_type msg)
{
	user_data->Log("Sending");

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

void CCore::ClientCore::ReceiveFrom()
{
	user_data->Log("Receiving");
	
	asio::async_read_until(sckt, received_message, "\r\n", 
		[this](const asio::error_code& e, std::size_t size)
		{
			if (e)
			{
				user_data->Log(e.message());

				received_message.consume(size);
			}
			else
			{
				user_data->GetMsg(received_message);

				received_message.consume(size);
			}
		}
	);
}