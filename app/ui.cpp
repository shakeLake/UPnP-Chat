#include "include/ui.hpp"

UserInterface::UserInterface()
{
	// data checking 
	size_of_msg_buffer = 0;

	// ui init
	setWindowTitle( style.GetTitle() );
	resize( style.GetWidth(), style.GetHeight() );	

	CreateToolBar();

	QWidget* main_widget = new QWidget(this);
	main_widget->setStyleSheet("background-color: white");

	QVBoxLayout* main_layout = new QVBoxLayout(main_widget);

	setCentralWidget(main_widget);

	// info 
	info_label = new QLabel("UPnP Chat");
	style.SetLabelFont(info_label);

	info_label->setFixedHeight(40);
	info_label->setAlignment(Qt::AlignCenter);

	// input field 
	input_field_layout = new QHBoxLayout();	

	send_button = new QPushButton();
	send_button->setStyleSheet("border: none");
	send_button->setIcon(QIcon(":/Resources/pics/send.png"));	
	send_button->setIconSize(QSize(40, 40));	
	
	main_text_field = new QTextEdit();
	style.SetTextEditFont(main_text_field);
	main_text_field->setFrameStyle(QFrame::NoFrame);
	main_text_field->setPlaceholderText("Write something...");
	main_text_field->setFixedHeight(50);
	
	input_field_layout->addWidget(main_text_field);
	input_field_layout->addWidget(send_button);

	// scroll area
	message_layout_widget = new QWidget;
	message_layout_widget->setStyleSheet("background-image: url(:/Resources/pics/background.png)");

	message_layout = new QVBoxLayout;
	message_layout->setSpacing(20);
	message_layout->addStretch(10);
	message_layout_widget->setLayout(message_layout);

	scroll_area = new QScrollArea;	
	scroll_area->setFrameShape(QFrame::NoFrame);
	scroll_area->setWidgetResizable( true );
	scroll_area->setWidget(message_layout_widget);

	// set main layout
	main_layout->setContentsMargins(0, 0, 0, 0);
	main_layout->setSpacing(0);
	main_layout->addWidget(info_label);
	main_layout->addWidget(scroll_area);
	main_layout->addLayout(input_field_layout);		
}

void UserInterface::CreateToolBar()
{
	tool_bar = new QToolBar();
	tool_bar->setFixedWidth(60);
	tool_bar->setStyleSheet("background-color: #161C32;"
							"spacing: 15px;");

	// set toolbar
	addToolBar(Qt::LeftToolBarArea, tool_bar);

	// property
	tool_bar->setMovable(false); 

	// widgets
	logo = new QPushButton;
	connect_to = new QPushButton;
	make_connection = new QPushButton;
	alr_opn_make_connection = new QPushButton;
	disconnect = new QPushButton;

	// widgets design
	logo->setIcon(QIcon(":/Resources/pics/logo.png"));
	logo->setStyleSheet("border: none");
	logo->setIconSize(QSize(40, 40));

	connect_to->setIcon(QIcon(":/Resources/pics/connect.png"));	
	connect_to->setStyleSheet("border: none");
	connect_to->setIconSize(QSize(36, 56));	
	connect(connect_to, &QPushButton::released, this, &UserInterface::ConnectionDialogSlot);

	make_connection->setIcon(QIcon(":/Resources/pics/upnp.png"));	
	make_connection->setStyleSheet("border: none");
	make_connection->setIconSize(QSize(40, 60));	
	connect(make_connection, &QPushButton::released, this, &UserInterface::MakeConnectionDialogSlot);

	alr_opn_make_connection->setIcon(QIcon(":/Resources/pics/nat_router.png"));	
	alr_opn_make_connection->setStyleSheet("border: none");
	alr_opn_make_connection->setIconSize(QSize(44, 64));	
	connect(alr_opn_make_connection, &QPushButton::released, this, &UserInterface::AlreadyOpenedDialogSlot);

	disconnect->setIcon(QIcon(":/Resources/pics/disconnect.png"));
	disconnect->setStyleSheet("border: none");
	disconnect->setIconSize(QSize(40, 60));

	// set widgets
	tool_bar->addWidget(logo);
	tool_bar->addWidget(connect_to);
	tool_bar->addWidget(make_connection);
	tool_bar->addWidget(alr_opn_make_connection);
	tool_bar->addWidget(disconnect);
}

// slots
void UserInterface::SendChatMessageSlot()
{
	msg_buffer = main_text_field->toPlainText();	
	msg = msg_buffer.toStdString();
	
	// clear
	main_text_field->clear();
	
	chat_client->SendTo( client_or_server_data.SetMessage(msg) );

	message_layout->addLayout( style.MessageEstablishing(msg, false) );	
}

void UserInterface::SendServerMessageSlot()
{
	msg_buffer = main_text_field->toPlainText();	
	msg = msg_buffer.toStdString();
	
	// clear
	main_text_field->clear();

	chat_server->SendTo( client_or_server_data.SetMessage(msg) );

	message_layout->addLayout( style.MessageEstablishing(msg, false) );	
}

void UserInterface::ConnectionDialogSlot()
{
	cdialog.exec();
	
	if (cdialog.result())
	{
		info_label->setText("Connecting...");
		info_label->repaint();

		// init
		chat_client = new ucc::Client(io_c, cdialog.ip_address, cdialog.port, &client_or_server_data);

		if (chat_client->connection_status)
		{
			// activate disconnect button
			connect(disconnect, &QPushButton::released, this, &UserInterface::Disconnect);

			info_label->setText("Connected");
			info_label->repaint();

			// Start client
			client_or_server_thread = std::thread( [this](){ io_c.run(); } );

			connect(send_button, &QPushButton::released, this, &UserInterface::SendChatMessageSlot);

			// Start data checking
			connect(this, &UserInterface::DataReceived, this, &UserInterface::AddMessage);
			data_checking_thread = std::thread(DataChecking, this);	
		}
		else
		{
			info_label->setText("Connection Refused");
			info_label->repaint();
			
			delete chat_client;
		}
	}
}

void UserInterface::MakeConnectionDialogSlot()
{
	mcdialog.exec();

	if (mcdialog.result())
	{
		client_or_server_data.Log("Opening port");		

		info_label->setText("Opening port...");
		info_label->repaint();

		// upnp init
		upnp = new SL_upnp::Upnp(mcdialog.port, mcdialog.port);
	
		if (upnp->PortForwarding())
		{
			client_or_server_data.Log("Port is opened");		

			info_label->setText("Waiting for connection...");
			info_label->repaint();

			// init
			chat_server = new ucs::Server(io_c, mcdialog.port, &client_or_server_data);

			if (chat_server->connection_status)
			{
				// activate disconnect button
				connect(disconnect, &QPushButton::released, this, &UserInterface::Disconnect);

				info_label->setText("Connected");
				info_label->repaint();

				// Start server
				client_or_server_thread = std::thread( [this](){ io_c.run(); } );

				connect(send_button, &QPushButton::released, this, &UserInterface::SendServerMessageSlot);

				// Start data checking
				connect(this, &UserInterface::DataReceived, this, &UserInterface::AddMessage);
				data_checking_thread = std::thread(DataChecking, this);	
			}
			else
			{
				info_label->setText("Failed");
				info_label->repaint();

				delete chat_server;
			}
		}
		else
		{
			info_label->setText("Failed");
			info_label->repaint();

			edialog = new ErrorDialog(er.upnp_failed);	

			edialog->exec();
			delete edialog;
		}
	}
}

void UserInterface::AlreadyOpenedDialogSlot()
{
	adialog.exec();
	
	if (adialog.result())
	{
		info_label->setText("Connecting...");
		info_label->repaint();

		// init
		chat_server = new ucs::Server(io_c, adialog.port, &client_or_server_data);

		if (chat_server->connection_status)
		{
			// activate disconnect button
			connect(disconnect, &QPushButton::released, this, &UserInterface::Disconnect);

			info_label->setText("Connected");
			info_label->repaint();

			// Start server
			client_or_server_thread = std::thread( [this](){ io_c.run(); } );

			connect(send_button, &QPushButton::released, this, &UserInterface::SendServerMessageSlot);

			// Start data checking
			connect(this, &UserInterface::DataReceived, this, &UserInterface::AddMessage);
			data_checking_thread = std::thread(DataChecking, this);	
		}
		else
		{
			info_label->setText("Connection Refused");
			info_label->repaint();
			
			delete chat_server;
		}
	}
}

void UserInterface::DataChecking()
{
	client_or_server_data.Log("Data checking started");

	while (client_or_server_data.StatusChecking())
	{
		client_or_server_data.Wait();

		if (client_or_server_data.GetMsgBufferSize() > size_of_msg_buffer)
		{
			emit DataReceived();			
		}
	}
}

void UserInterface::AddMessage()
{
	client_or_server_data.Log("emit Data Receiving");

	try
	{
		message_layout->addLayout(
			style.MessageEstablishing(
					client_or_server_data.GetMsgFromMsgBuffer(size_of_msg_buffer), true)
		);	
	}
	catch(const std::exception& e)
	{
		std::cout << "New message exception" << std::endl;
	}

	std::cout << client_or_server_data.GetMsgFromMsgBuffer(size_of_msg_buffer) << std::endl;

	size_of_msg_buffer = client_or_server_data.GetMsgBufferSize();	

	std::cout << client_or_server_data.GetMsgBufferSize() << std::endl;
	std::cout << size_of_msg_buffer << std::endl;
}

void UserInterface::Disconnect()
{
	client_or_server_data.Log("Disconnect");

	delete chat_client;
	delete chat_server;

	// data checking reset
	client_or_server_data.NotifyOne();
	client_or_server_data.StatusDisconnected();

	client_or_server_thread.join();
	data_checking_thread.join();

	delete upnp;
}

UserInterface::~UserInterface()
{
	client_or_server_data.Log("Disconnect Destructor");

	delete chat_client;
	delete chat_server;

	// data checking reset
	client_or_server_data.NotifyOne();
	client_or_server_data.StatusDisconnected();

	client_or_server_thread.join();
	data_checking_thread.join();

	delete upnp;
}
