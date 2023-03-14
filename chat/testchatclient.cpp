#include "include/default.hpp"

int main()
{
	asio::io_context io_c;	

	std::thread t1( [&io_c](){ io_c.run(); } );

	std::string ip = "127.0.0.1";
	std::string port = "50000";
	ucc::Client test_client(io_c, ip, port);	

	t1.join();
	
	return 0;	
}
