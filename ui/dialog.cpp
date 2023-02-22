#include "include/dialog.hpp"

ConnectionDialog::ConnectionDialog()
{
	QWidget* main_widget = new QWidget(this);
	
	// properties
	this->setCentralWidget(main_widget);

	QVBoxLayout* main_layout = new QVBoxLayout(main_widget);
	
	main_label = new QLabel("Where to connect:");
	main_layout->addWidget(main_label);
	
	edit_ip = new QLineEdit();
	main_layout->addWidget(edit_ip);

	QHBoxLayout* button_layout = new QHBoxLayout();
	cancel_button = new QPushButton("cancel"); 
	connect_button = new QPushButton("connect");
	
	button_layout->addWidget(cancel_button);
	button_layout->addWidget(connect_button);

	main_layout->addLayout(button_layout);
}
