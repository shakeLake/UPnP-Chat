#include "include/dialog.hpp"

ConnectionDialog::ConnectionDialog()
{
	setWindowTitle("Login");
	resize(350, 150);	

	QWidget* main_widget = new QWidget(this);

	CreateToolBar();
			
	// properties
	setCentralWidget(main_widget);
	
	// init
	main_label = new QLabel("1");

	edit_ip = new QLineEdit();
	edit_port = new QLineEdit();	

	cancel_button = new QPushButton("Cancel"); 
	task_button = new QPushButton;

	StateMachine();

	// main_label
	main_layout = new QVBoxLayout(main_widget);
	
	main_layout->addWidget(main_label);
	
	/* 
		"edit_ip" requirements: 000.000.000.000
	*/
	label_line_edit_ip = new QFormLayout();
	label_line_edit_port = new QFormLayout();

	ip_label = new QLabel("IP address");
	port_label = new QLabel("Port");
	
	label_line_edit_ip->addRow(ip_label, edit_ip);
	label_line_edit_port->addRow(port_label, edit_port);
	
	// button layout
	button_layout = new QHBoxLayout();	
	connect(cancel_button, &QPushButton::released, this, [this](){ close(); });	

	connect(task_button, &QPushButton::released, this, &ConnectionDialog::GetIpAddress);

	button_layout->addWidget(cancel_button);
	button_layout->addWidget(task_button);

	main_layout->addLayout(label_line_edit_ip);
	main_layout->addLayout(label_line_edit_port);
	main_layout->addLayout(button_layout);	
}

void ConnectionDialog::StateMachine()
{
	state_machine = new QStateMachine();

	connect_state = new QState();
	connect_state->assignProperty(main_label, "Where to connect", "state 1");	
	connect_state->assignProperty(task_button, "Connect", "state 1");
	connect_state->addTransition(listen_to, &QPushButton::clicked, make_connection_state); 

	make_connection_state = new QState();
	make_connection_state->assignProperty(main_label, "Press button to open port", "state 2");	
	make_connection_state->assignProperty(task_button, "Make Connection", "state 2");
	make_connection_state->addTransition(connect_to, &QPushButton::clicked, connect_state);
	
	state_machine->addState(connect_state);
	state_machine->addState(make_connection_state);
	
	state_machine->setInitialState(make_connection_state);
	state_machine->start();
}

void ConnectionDialog::CreateToolBar()
{
	tool_bar = addToolBar("ToolBar");

	connect_to = new QPushButton;		
	listen_to = new QPushButton;		

	tool_bar->addWidget(connect_to);

	tool_bar->addSeparator();

	tool_bar->addWidget(listen_to);
}

void ConnectionDialog::GetIpAddress()
{
	// check string 
	
	str = edit_ip->text();	
	ip_address = str.toStdString();
	
	std::cout << ip_address << std::endl;
}
