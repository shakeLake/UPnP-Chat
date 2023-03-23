#ifndef UI_HPP_
#define UI_HPP_

// I / O
#include <iostream>

// chat 
#include "../../chat/include/default.hpp"

// design
#include "design.hpp"

// dialogs
#include "connectiondialog.hpp"
#include "makeconnectiondialog.hpp"
#include "acceptdialog.hpp"
#include "errordialog.hpp"

// qt
#include <QApplication>
#include <QMainWindow>
#include <QString>
#include <QPixmap>

// layouts
#include <QVBoxLayout>
#include <QHBoxLayout>

// widgets
#include <QToolBar>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>

// scrolls
#include <QScrollArea>

class UserInterface : public QMainWindow
{
	Q_OBJECT

private:
	Design style;
		
	// chat
	ErrorMessage er;

	ucd::Data client_or_server_data;
			
	std::thread client_or_server_thread;

	asio::io_context io_c;

	// client chat
	ucc::Client* chat_client;

	// server chat
	ucs::Server* chat_server;		
			
	// upnp
	SL_upnp::Upnp* upnp;

	// toolbar
	QToolBar* tool_bar;
			
	QPixmap connect_to_pixmap;			
	QPushButton* connect_to;
				
	QPixmap make_connection_pixmap;			
	QPushButton* make_connection;
			
	// dialogs
	ConnectionDialog cdialog;
	MakeConnectionDialog mcdialog;
	ErrorDialog* edialog;

	// chat widgets
	QString msg_buffer;
	std::string msg;

	QLabel* info_label;
	QHBoxLayout* input_field_layout;
	QPushButton* send_button;
	QTextEdit* main_text_field;
		
	// message 			
	QVBoxLayout* message_layout;
	QLabel* message;
	QFont font;		

	// scrolls
	QWidget* message_layout_widget;
	QScrollArea* scroll_area;

private slots:
	void ConnectionDialogSlot();

	void SendChatMessageSlot();
	void SendServerMessageSlot();

	void MakeConnectionDialogSlot();

private:
	// toolbar
	void CreateToolBar();

public:
	UserInterface();
	~UserInterface();	
};

#endif /* UI_HPP */
