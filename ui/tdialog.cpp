#include "inlcude/dialog.hpp"

int main(int argc, char* argv[])
{
	QApplication app(argc, argc);

	ConnectionDialog test_dialog;
	test_dialog.show();

	return app.exec();
}
