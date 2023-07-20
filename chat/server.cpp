#include "include/server.hpp"

void ucs::Server::Listening()
{
	user_data->Log("Listening");	
		
	accptr.accept(sckt, endpnt, error);
    
	if (error)
    {
    	user_data->Log(error.message());
		
		connection_status = 0;
   	}
    else
    {
    	user_data->Log("Connected");

		connection_status = 1;		

		//std::string ip = endpnt.address().to_string();

		ReceiveFrom(action);
    }
}
