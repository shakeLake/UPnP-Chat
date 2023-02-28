#include "include/makeconnectiondialog.hpp"
//#include "include/connectiondialog.hpp"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	MakeConnectionDialog test_dialog;
	test_dialog.show();

	return app.exec();
}
