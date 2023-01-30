#include "client.hpp"

ucc::Client::Client(ucd::Data& d)
{
    info = d;

    rslvr = io_c;
    sckt = io_c;

    endpnt = rslvr.resolve(info->GetIpaddr(), info->port, error);
    ErrorHandler(error);
}

void ucc::Client::ErrorHandler(asio::error_code er)
{
    if (ec)
    {
        std::cerr << "Error: ";
        std::cerr << ec.message() << std::endl;
        return;
    }
}

bool ucc::Client::Connect()
{
    asio::connect(sckt, endpnt, 
        [](const asio::error_code& ec, const asio::ip::tcp::endpoint& next)
        {
            if (ec)
            {
                std::cerr << ec.message() << std::endl;
                return false;
            }
            else
            {
                std::cout << "Connecting to: " << next << std::endl;
                return true;
            }
        }
    );
    
    std::cout << "Connected" << std::endl;

    return sckt.is_open();
}