#include "include/dialog.hpp"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	ConnectionDialog test_dialog;
	test_dialog.show();

	return app.exec();
}
