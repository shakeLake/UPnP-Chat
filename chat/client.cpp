#include "include/client.hpp"

void ucc::Client::Connect()
{
	asio::connect(sckt.next_layer(), endpnt, error);
 	
	if (error)
	{
		user_data->Log(error.message());
		
		connection_status = false;	
	}
	else
	{
		user_data->Log("Connected");

		connection_status = true;
				
		Handshake(true);
	}
}

bool ucc::Client::isConnected()
{
	return connection_status;
}