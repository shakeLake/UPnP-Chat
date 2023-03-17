#include "include/makeconnectiondialog.hpp"

MakeConnectionDialog::MakeConnectionDialog()
{
	setWindowTitle("Make Connection");
	resize(350, 150);	

	QWidget* main_widget = new QWidget(this);
			
	// init
	main_label = new QLabel("This menu will open port on your router by UPNP!\nbe sure UPNP is on. If your router doesn't support UPNP\nyou can use Port Forwarding");

	port_label = new QLabel("Port");
	edit_port = new QLineEdit();	

	cancel_button = new QPushButton("Cancel"); 
	task_button = new QPushButton("Create");

	// main_label
	main_layout = new QVBoxLayout(main_widget);	

	// port layout	
	label_line_edit_port = new QFormLayout();
	label_line_edit_port->addRow(port_label, edit_port);
	
	// button layout
	button_layout = new QHBoxLayout();	
	connect(cancel_button, &QPushButton::released, this, [this](){ reject(); });	

	connect(task_button, &QPushButton::released, this, &MakeConnectionDialog::GetPort);

	button_layout->addWidget(cancel_button);
	button_layout->addWidget(task_button);

	main_layout->addWidget(main_label);
	main_layout->addLayout(label_line_edit_port);
	main_layout->addLayout(button_layout);	
}

void MakeConnectionDialog::GetPort()
{
	// check string 
	port_str = edit_port->text();	
	port = port_str.toStdString();

	std::cout << port << std::endl;
	
	accept();
}
