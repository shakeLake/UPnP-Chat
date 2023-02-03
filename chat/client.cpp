#include "include/client.hpp"

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