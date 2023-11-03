#include "include/server.hpp"

void ucs::Server::Listening()
{
	user_data->Log("Listening");	
		
	accptr.accept(sckt.lowest_layer(), endpnt, error);

	if (error)
	{
		user_data->Log(error.message());
		
		connection_status = false;
	}
	else
	{
		user_data->Log("Connected");

		connection_status = true;

		Handshake();
	}
}

bool ucs::Server::isConnected()
{
	return connection_status;
}