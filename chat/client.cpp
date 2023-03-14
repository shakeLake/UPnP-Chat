#include "include/client.hpp"

void ucc::Client::Connect()
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

	ReceiveFrom();
}

void ucc::Client::SendTo(asio::streambuf::const_buffers_type msg)
{
	std::cout << "sending" << std::endl;

    unsigned int bytes_transfered = asio::write(sckt, msg, asio::transfer_all(), error);

    if (error)
    {
        std::cerr << "Sending error: ";
        std::cerr << error.message() << std::endl;
    }
}

void ucc::Client::ReceiveFrom()
{
	std::cout << "receiving" << std::endl;

	unsigned int bytes_transfered = asio::read_until(sckt, received_message, '\n', error);

	if (error)
	{
		std::cerr << "Receiving error: ";
		std::cerr << error.message() << std::endl;	
	}
	else 
	{
		std::cout << "Bytes Transfered: " << bytes_transfered << std::endl;
	}
}
