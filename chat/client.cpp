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

void ucc::Client::SendTo(asio::streambuf::const_buffers_type msg)
{
    unsigned int bytes_transfered = asio::write(sckt, msg, asio::transfer_all(), error);

    if (error)
    {
        std::cerr << "Sending error: ";
        std::cout << error.message() << std::endl;
    }
}