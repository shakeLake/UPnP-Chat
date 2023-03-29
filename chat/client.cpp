#include "include/client.hpp"

void ucc::Client::Connect()
{
    asio::connect(sckt, endpnt, error);
 
   	if (error)
    {
    	std::cerr << error.message() << std::endl;
		
		connection_status = false;
	}
    else
    {
    	std::cout << "Connected" << std::endl;
				
		connection_status = true;

		ReceiveFrom(action);
    }
}

bool ucc::Client::SocketIsOpen()
{
	return sckt.is_open();
}
