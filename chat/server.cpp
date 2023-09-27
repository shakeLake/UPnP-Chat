#include "include/server.hpp"

void ucs::Server::Listening()
{
	user_data->Log("Listening");	
		
	accptr.accept(sckt, endpnt, error);

	if (error)
	{
		user_data->Log(error.message());
		
		connection_status = false;
	}
	else
	{
		user_data->Log("Connected");

		connection_status = true;		

		//std::string ip = endpnt.address().to_string();

		ReceiveFrom(action);
	}
}

bool ucs::Server::isConnected()
{
	return connection_status;
}