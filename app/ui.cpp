#include "include/ui.hpp"

UserInterface::UserInterface()
{
	// ui init
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
	connect(send_button, &QPushButton::released, this, &UserInterface::SendMessageSlot);
	
	main_text_field = new QTextEdit();
	main_text_field->setFixedHeight(50);
	
	input_field_layout->addWidget(main_text_field);
	input_field_layout->addWidget(send_button);

	// scroll area
	message_layout_widget = new QWidget;
	message_layout = new QVBoxLayout;

	message_layout_widget->setLayout(message_layout);

	scroll_area = new QScrollArea();	
	scroll_area->setWidgetResizable( true );
	scroll_area->setWidget(message_layout_widget);

	// set main layout
	main_layout->addWidget(info_label);
	main_layout->addWidget(scroll_area);
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
	connect(connect_to, &QPushButton::released, this, &UserInterface::ConnectionDialogSlot);

	make_connection_pixmap.load(":icons/share.png");
	make_connection->setIcon(connect_to_pixmap);	
	make_connection->setIconSize(QSize(20, 20));	
	connect(make_connection, &QPushButton::released, this, &UserInterface::MakeConnectionDialogSlot);

	// set widgets
	tool_bar->addWidget(connect_to);
	tool_bar->addWidget(make_connection);
}

// slots
void UserInterface::SendMessageSlot()
{
	msg_buffer = main_text_field->toPlainText();	
	msg = msg_buffer.toStdString();
	
	chat_client->SendTo( client_or_server_data.SetMessage(msg) );

	message_layout->addWidget( style.LabelEstablish(msg, false) );	
}

void UserInterface::ConnectionDialogSlot()
{
	cdialog.exec();
	
	if (cdialog.result())
	{
		// init
		chat_client = new ucc::Client(io_c, cdialog.ip_address, cdialog.port);

		client_or_server_thread = std::thread( [this](){ io_c.run(); } );
	}
}

void UserInterface::MakeConnectionDialogSlot()
{
	mcdialog.exec();

	if (mcdialog.result())
	{
		// upnp init
		upnp = new SL_upnp::Upnp(mcdialog.port, mcdialog.port);
		upnp->PortForwarding();

		// init
		chat_server = new ucs::Server(io_c, mcdialog.port);

		client_or_server_thread = std::thread( [this](){ io_c.run(); } );
	}
}

UserInterface::~UserInterface()
{
	client_or_server_thread.join();

	delete chat_client;
}
