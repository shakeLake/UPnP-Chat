#include "include/default.hpp"

int main()
{
	asio::io_context io_c;

	ucc::Client test_client(io_c, 127.0.0.1, 50000);	

	test_client.Connect();
	
	return 0;	
}
