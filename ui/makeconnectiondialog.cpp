#include "include/makeconnectiondialog.hpp"

MakeConnectionDialog::MakeConnectionDialog()
{
	setWindowTitle("Make Connection");
	resize(350, 150);	

	QWidget* main_widget = new QWidget(this);
			
	// init
	main_label = new QLabel("This menu opens the port");

	ip_label = new QLabel("IP address");
	port_label = new QLabel("Port");
	
	ip_text = new QLabel("IP ADDRESS");
	edit_port = new QLineEdit();	

	cancel_button = new QPushButton("Cancel"); 
	task_button = new QPushButton("Connect");

	// main_label
	main_layout = new QVBoxLayout(main_widget);	
	
	/* 
		"edit_ip" requirements: 000.000.000.000
	*/
	label_line_edit_ip = new QFormLayout();
	label_line_edit_port = new QFormLayout();
	
	label_line_edit_ip->addRow(ip_label, ip_text);
	label_line_edit_port->addRow(port_label, edit_port);
	
	// button layout
	button_layout = new QHBoxLayout();	
	connect(cancel_button, &QPushButton::released, this, [this](){ reject(); });	

	connect(task_button, &QPushButton::released, this, [this](){ accept_message = true; });

	button_layout->addWidget(cancel_button);
	button_layout->addWidget(task_button);

	main_layout->addWidget(main_label);
	main_layout->addLayout(label_line_edit_ip);
	main_layout->addLayout(label_line_edit_port);
	main_layout->addLayout(button_layout);	
}
