#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include "clientcore.hpp"

namespace ucc
{
    class Client : public ClientCore
    {
    private:
    	// .resolve
        asio::ip::tcp::resolver rslvr;

        // endpoint
        asio::ip::tcp::resolver::results_type endpnt;
			
	// error code			
        asio::error_code error;
	
    public:
	// connection status
	bool connection_status;

    private:
    	/* connects to specific ip address */
	void Connect();

    public:
    	Client(asio::io_context& io_c, std::string& ip, std::string& port, ucd::Data* u_d) 
	:	rslvr(io_c), 
		ClientCore(io_c, u_d)
        {				
        	endpnt = rslvr.resolve(ip, port, error);

            	if (error)
           	{
			u_d->Log(error.message());
            	}

            	Connect();
	}

        ~Client()
	{
		user_data->Log("Client Core destructor");
	}
    };
}

#endif /* CLIENT_HPP_ */
