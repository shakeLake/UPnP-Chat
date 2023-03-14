#include "include/default.hpp"

int main()
{
	std::string ip = "127.0.0.1";
	std::string port = "50000";
		
	ucd::Data test_data(ip);

	asio::io_context io_c;	

	ucc::Client test_client(io_c, ip, port);	

	std::thread t1( [&io_c](){ io_c.run(); } );

	test_client.SendTo( test_data.SetMessage(port) );

	t1.join();
	
	return 0;	
}
