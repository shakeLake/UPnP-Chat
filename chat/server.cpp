#include "include/server.hpp"

std::string ucs::Server::Listening()
{
    std::cout << "Listening" << std::endl;
    
    accptr.accept(sckt, endpnt, error);
    
    if (error)
    {
        std::cerr << "Acceptor error: ";
        std::cerr << error.message() << std::endl;
        assert(error);
    }

    std::string ip = endpnt.address().to_string();

    return ip;
}

void ucs::Server::ReadFrom()
{
    unsigned int bytes_transfered = asio::read_until(sckt, data, '\n', error);

    if (error)
    {
        std::cerr << "Reading error: ";
        std::cerr << error.message() << std::endl;
    }
    else
    {
        std::cout << "Bytes transfered: " << bytes_transfered << std::endl;
    }
}