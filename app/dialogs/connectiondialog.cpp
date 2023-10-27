#include "include/connectiondialog.hpp"

ConnectionDialog::ConnectionDialog()
{
	const int height = 150;
	const int width = 350;

	setWindowTitle("Connect");
	setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::FramelessWindowHint);	
	setAttribute(Qt::WA_TranslucentBackground);

	resize(width, height);	

	QWidget* main_widget = new QWidget(this);
	main_widget->setFixedSize(width, height);
	main_widget->setStyleSheet("background-color: white;"
								"border-radius: 10px;");
			
	// init
	main_label = new QLabel("Where to connect?");
	style.SetNunitoLabelFont(main_label);	
	main_label->setStyleSheet("font-size: 18px");

	ip_label = new QLabel("IP address:");
	style.SetNunitoLabelFont(ip_label);

	port_label = new QLabel("     Port:     ");
	style.SetNunitoLabelFont(port_label);
	
	edit_ip = new QLineEdit();
	edit_ip->setPlaceholderText(" ip address");
	edit_ip->setFixedHeight(25);
	edit_ip->setStyleSheet("background-color: #F1DAC4;"
			       "border-radius: 5px;"
			       "color: #161C32;");
	style.SetNunitoLineFont(edit_ip);

	edit_port = new QLineEdit();	
	edit_port->setPlaceholderText(" 49152 - 65535");
	edit_port->setFixedHeight(25);
	edit_port->setStyleSheet("background-color: #F1DAC4;"
				 "border-radius: 5px;"
				 "color: #161C32");
	style.SetNunitoLineFont(edit_port);

	cancel_button = new QPushButton("Cancel"); 
	cancel_button->setFixedSize(100, 24);
	cancel_button->setStyleSheet("border-radius: 5px");

	task_button = new QPushButton("Connect");
	task_button->setFixedSize(125, 24);
	task_button->setStyleSheet("background-color: #161C32;"
				   "color: white;"
				   "border-radius: 5px");

	// main_label
	main_layout = new QVBoxLayout(main_widget);	
	
	/* 
		"edit_ip" requirements: 000.000.000.000
	*/
	label_line_edit_ip = new QFormLayout();
	label_line_edit_port = new QFormLayout();
	
	label_line_edit_ip->addRow(ip_label, edit_ip);
	label_line_edit_port->addRow(port_label, edit_port);
	
	// button layout
	button_layout = new QHBoxLayout();	
	connect(cancel_button, &QPushButton::released, this, [this](){ reject(); });	

	connect(task_button, &QPushButton::released, this, &ConnectionDialog::GetIpAddressAndPort);

	button_layout->setAlignment(Qt::AlignRight);
	button_layout->addWidget(cancel_button);
	button_layout->addWidget(task_button);

	main_layout->addWidget(main_label);
	main_layout->addLayout(label_line_edit_ip);
	main_layout->addLayout(label_line_edit_port);
	main_layout->addLayout(button_layout);	
}

void ConnectionDialog::GetIpAddressAndPort()
{
	// check string 
	
	ip_str = edit_ip->text();	
	ip_address = ip_str.toStdString();
	
	port_str = edit_port->text();	
	port = port_str.toStdString();

	if (!ip_address.empty() && !port.empty())
	{
		std::cout << ip_address << std::endl;
		std::cout << port << std::endl;
		
		accept();
	}
}