#include "include/errordialog.hpp"

ErrorDialog::ErrorDialog(std::string& er_msg)
{
	setWindowTitle("Error dialog");
	resize(350, 150);

	center_widget = new QWidget(this);

	main_layout = new QVBoxLayout(center_widget);

	error_message = new QLabel(QString::fromStdString(er_msg));	
	okay_button = new QPushButton("Ok");

	main_layout->addWidget(error_message);
	main_layout->addWidget(okay_button);
}
