#include "server.hpp"

void ucs::Server::Listening()
{
    accptr.accept(sckt, endpnt, error);
    
    if (error)
    {
        std::cerr << "Acceptor error: ";
        std::cerr << error.message() << std::endl;
        assert(error);
    }
}