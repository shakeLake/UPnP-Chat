#include "include/acceptdialog.hpp"

AcceptDialog::AcceptDialog(char* lan_addr, char* port)
{
	setWindowTitle("Trying...");
	resize(350, 150);

	center_widget = new QWidget(this);
	main_layout = new QVBoxLayout(center_widget);
	
	invite_code = new QLabel(lan_addr);
	waiting_label = new QLabel("waiting...");

	main_layout->addWidget(invite_code);
	main_layout->addWidget(waiting_label);
}
