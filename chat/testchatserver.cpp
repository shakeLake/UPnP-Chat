#include "include/default.hpp"

int main()
{
	ucd::Data test_data;	

	asio::io_context io_c;

	std::string port = "50000";
	ucs::Server test_server(io_c, port);

	std::thread t1( [&io_c](){ io_c.run(); } );	

	test_server.SendTo( test_data.SetMessage(port) );

	t1.join();

	return 0;
}
