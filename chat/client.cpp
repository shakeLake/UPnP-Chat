#include "include/client.hpp"

void ucc::Client::Connect()
{
    asio::connect(sckt, endpnt, error);
 
   	if (error)
    {
    	user_data->Log(error.message());
		
		connection_status = false;
	}
    else
    {
    	user_data->Log("Connected");
				
		connection_status = true;

		ReceiveFrom(action);
    }
}
