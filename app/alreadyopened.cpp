#include "include/alreadyopened.hpp"

AlreadyOpenedDialog::AlreadyOpenedDialog()
{
	setWindowTitle("Make Connection");
	setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);	
	resize(365, 120);	

	QWidget* main_widget = new QWidget(this);
	main_widget->setFixedSize(365, 120);
	main_widget->setStyleSheet("background-color: white");
			
	// init
	main_label = new QLabel("Enter the port which you opened on your router.\nProgram will listening this port.");
	style.SetNunitoLabelFont(main_label);	

	port_label = new QLabel("Port:");
	style.SetNunitoLabelFont(port_label);

	edit_port = new QLineEdit();	
	edit_port->setPlaceholderText("49152 - 65535");
	edit_port->setFixedHeight(25);
	edit_port->setStyleSheet("background-color: #F1DAC4;"
				 "border-radius: 5px;"
				 "color: #161C32");
	style.SetNunitoLineFont(edit_port);

	cancel_button = new QPushButton("Cancel"); 
	cancel_button->setFixedSize(100, 24);
	cancel_button->setStyleSheet("border-radius: 5px");

	task_button = new QPushButton("Listen");
	task_button->setFixedSize(125, 24);
	task_button->setStyleSheet("background-color: #161C32;"
				   "color: white;"
				   "border-radius: 5px");

	// main_label
	main_layout = new QVBoxLayout(main_widget);	

	// port layout	
	label_line_edit_port = new QFormLayout();
	label_line_edit_port->addRow(port_label, edit_port);
	
	// button layout
	button_layout = new QHBoxLayout();	
	connect(cancel_button, &QPushButton::released, this, [this](){ reject(); });	

	connect(task_button, &QPushButton::released, this, &AlreadyOpenedDialog::GetPort);

	button_layout->setAlignment(Qt::AlignRight);
	button_layout->addWidget(cancel_button);
	button_layout->addWidget(task_button);

	main_layout->addWidget(main_label);
	main_layout->addLayout(label_line_edit_port);
	main_layout->addLayout(button_layout);	
}

void AlreadyOpenedDialog::GetPort()
{
	// check string 
	port_str = edit_port->text();	
	port = port_str.toStdString();

	std::cout << port << std::endl;
	
	accept();
}
