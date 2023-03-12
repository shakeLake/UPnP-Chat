// ui
#include "include/ui.hpp"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	asio::io_context io_c;
	std::thread t1( []() { io_c.run() } );

	UserInterface main_ui(io_c);

	main_ui.show();

	t1.join();

    return app.exec();
}
