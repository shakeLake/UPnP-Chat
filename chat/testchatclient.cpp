#include "include/default.hpp"

int main()
{
	std::string ip = "127.0.0.1";
	std::string port = "50000";

	ucd::Data test_data(ip);	

	asio::io_context io_c;	

	ucc::Client test_client(io_c, ip, port);	

	std::string text = "Hello!";
	test_client.SendTo( test_data.SetMessage(text) );

	std::thread t1( [&io_c](){ io_c.run(); } );

	t1.join();
	
	return 0;	
}
