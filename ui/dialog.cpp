#include "include/dialog.hpp"

ConnectionDialog::ConnectionDialog()
{
	setWindowTitle("Login");
	resize(350, 150);	

	QWidget* main_widget = new QWidget(this);
	
	// properties
	// ...

	QVBoxLayout* main_layout = new QVBoxLayout(main_widget);
	
	/* 
	 	main_label
	*/
	main_label = new QLabel("Where to connect:");
	main_layout->addWidget(main_label);
	
	/* 
		"edit_ip" requirements: 000.000.000.000
	*/
	edit_ip = new QLineEdit();
	main_layout->addWidget(edit_ip);

	QHBoxLayout* button_layout = new QHBoxLayout();
	cancel_button = new QPushButton("Cancel"); 
	connect(cancel_button, &QPushButton::released, this, [this](){ reject(); });	

	connect_button = new QPushButton("Connect");
	connect(connect_button, &QPushButton::released, this, &ConnectionDialog::GetIpAddress);
	
	button_layout->addWidget(cancel_button);
	button_layout->addWidget(connect_button);

	main_layout->addLayout(button_layout);
}

void ConnectionDialog::GetIpAddress()
{
	// check string 
	
	str = edit_ip->text();	
	ip_address = str.toStdString();
}
