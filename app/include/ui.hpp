#ifndef UI_HPP_
#define UI_HPP_

// I / O
#include <iostream>

// chat 
#include "../../chat/include/default.hpp"

// design
#include "design.hpp"

// dialogs
#include "../dialogs/include/connectiondialog.hpp"
#include "../dialogs/include/makeconnectiondialog.hpp"
#include "../dialogs/include/alreadyopened.hpp"
#include "../dialogs/include/errordialog.hpp"

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

	// synch
	std::mutex mtx;

	// client chat
	ucc::Client* chat_client;

	// server chat
	ucs::Server* chat_server;		
			
	// upnp
	SL_upnp::Upnp* upnp;

	// data checking
	std::thread data_checking_thread;
	unsigned int size_of_msg_buffer;

	// toolbar
	QToolBar* tool_bar;
	
	QPushButton* logo;

	QPushButton* connect_to;
				
	QPushButton* make_connection;

	QPushButton* alr_opn_make_connection;

	QPushButton* disconnect;
			
	// dialogs
	ConnectionDialog cdialog;
	MakeConnectionDialog mcdialog;
	AlreadyOpenedDialog adialog;
	ErrorDialog* edialog;

	// chat widgets
	QString msg_buffer;

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
	void MakeConnectionDialogSlot();
	void AlreadyOpenedDialogSlot();

	void SendChatMessageSlot();
	void SendServerMessageSlot();

signals:
	void DataReceived();

private:
	// toolbar
	void CreateToolBar();

	// data checking -- thread
	void DataChecking(); 

	// data checking slot
	void AddMessage();

	// disconnect
	void Disconnect();

	// deletes redundant symbols
	void RedundantSymbols(std::string&);

public:
	UserInterface();
	~UserInterface();	
};

#endif /* UI_HPP */
