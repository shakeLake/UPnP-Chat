#include "include/acceptdialog.hpp"
AcceptDialog::AcceptDialog(const std::string& inv_code)
{
	setDisabled(true);

	setWindowTitle("Trying...");
	resize(350, 150);

	center_widget = new QWidget(this);
	main_layout = new QVBoxLayout(center_widget);
	
	invite_code = new QLabel(QString::fromStdString(inv_code));
	waiting_label = new QLabel("waiting...");

	main_layout->addWidget(invite_code);
	main_layout->addWidget(waiting_label);
}
