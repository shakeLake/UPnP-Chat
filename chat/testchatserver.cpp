#include "include/default.hpp"

int main()
{
	asio::io_context io_c;

	std::string port = "50000";
	ucs::Server test_server(io_c, port);

	std::thread t1( [&io_c](){ io_c.run(); } );	

	t1.join();

	return 0;
}
