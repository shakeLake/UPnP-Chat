#include "include/ui.hpp"

UserInterface::UserInterface()
{
	setWindowTitle( style.GetTitle() );
	resize( style.GetWidth(), style.GetHeight() );	

	CreateToolBar();

	QWidget* main_widget = new QWidget(this);
	QVBoxLayout* main_layout = new QVBoxLayout(main_widget);

	setCentralWidget(main_widget);
	
	// info 
	info_label = new QLabel("Information");
	info_label->setAlignment(Qt::AlignTop);
	info_label->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	// input field 
	input_field_layout = new QHBoxLayout();	

	send_button = new QPushButton("send");
	main_text_field = new QTextEdit();
	
	input_field_layout->addWidget(main_text_field);
	input_field_layout->addWidget(send_button);

	// set messages
	message_layout = new QVBoxLayout();	
	message_layout->addWidget( style.LabelEstablish("Test Message", true) );	
	message_layout->addWidget( style.LabelEstablish("Test Message 1", false) );	

	// set main layout
	main_layout->addWidget(info_label);
	main_layout->addLayout(message_layout);
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
