#include "include/ui.hpp"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	UserInterface test_ui;
	test_ui.show();

	return app.exec();
}
