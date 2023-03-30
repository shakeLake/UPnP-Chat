#ifndef SERVER_HPP_
#define SERVER_HPP_

#include "clientcore.hpp"

namespace ucs
{
    class Server : public ClientCore
    {
    private:
        asio::error_code error;

        asio::ip::tcp::endpoint endpnt;
        asio::ip::tcp::acceptor accptr;

		// buffer
		asio::streambuf received_message;	

	public:
		// connection status
		bool connection_status;
			
	private:		
		/* listen connection */
       	void Listening();

    public:
    	Server(asio::io_context& io_c, std::string& port, ucd::Data* u_d) 
		:	ClientCore(io_c, u_d),
			endpnt(asio::ip::tcp::v4(),
			stoi(port)),
			accptr(io_c, endpnt)
        {
            Listening();
        }             
            
        ~Server() = default;

		// return socket.is_open()
		bool SocketIsOpen();
    };
}

#endif /* SERVER_HPP */
