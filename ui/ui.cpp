#include "include/ui.hpp"

UserInterface::UserInterface()
{
	setWindowTitle("Chat");
	resize(900, 600);	

	CreateToolBar();

	QWidget* main_widget = new QWidget(this);
	QVBoxLayout* main_layout = new QVBoxLayout(main_widget);

	setCentralWidget(main_widget);

	// input field 
	input_field_layout = new QHBoxLayout();	

	send_button = new QPushButton("send");
	main_text_field = new QTextEdit();
	
	input_field_layout->addWidget(main_text_field);
	input_field_layout->addWidget(send_button);

	main_layout->addLayout(input_field_layout);		
}

void UserInterface::CreateToolBar()
{
	tool_bar = new QToolBar();
	// set toolbar
	addToolBar(Qt::LeftToolBarArea, tool_bar);

	// property
	tool_bar->setMovable(false); 

	// widgets
	connect_to = new QPushButton;
	make_connection = new QPushButton;

	// widgets design
	connect_to_pixmap.load(":icons/arrow.png");
	connect_to->setIcon(connect_to_pixmap);	
	connect_to->setIconSize(QSize(20, 20));	

	make_connection_pixmap.load(":icons/share.png");
	make_connection->setIcon(connect_to_pixmap);	
	make_connection->setIconSize(QSize(20, 20));	

	// set widgets
	tool_bar->addWidget(connect_to);
	tool_bar->addWidget(make_connection);
}
