// ui
#include "include/ui.hpp"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	app.setWindowIcon(QIcon(":/Resources/pics/logo.png"));

	UserInterface main_ui;

	main_ui.show();

	return app.exec();
}
