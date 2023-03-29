#include "include/server.hpp"

void ucs::Server::Listening()
{
    std::cout << "Listening" << std::endl;
    
    accptr.accept(sckt, endpnt, error);
    
    if (error)
    {
        std::cerr << "Acceptor error: ";
        std::cerr << error.message() << std::endl;
		
		connection_status = 0;
    }
	else
	{
		connection_status = 1;		

	    std::string ip = endpnt.address().to_string();

		ReceiveFrom(action);
	}
}

bool ucs::Server::SocketIsOpen()
{
	return sckt.is_open();
}
