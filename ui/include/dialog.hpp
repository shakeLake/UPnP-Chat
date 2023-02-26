#ifndef DIALOG_HPP_
#define DIALOG_HPP_

// i / o
#include <iostream>

// qt / application
#include <QApplication>
#include <QMainWindow>

// qt / layouts
#include <QVBoxLayout>
#include <QHBoxLayout>

// qt / state machine
#include <QStateMachine>
#include <QState>

// qt gui
#include <QFormLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QToolBar>

class ConnectionDialog : public QMainWindow
{
	Q_OBJECT
	
	private:
		// main label
		QVBoxLayout* main_layout;	
		QLabel* main_label;
	
		// toolbar
		QToolBar* tool_bar;
		QPushButton* connect_to;
		QPushButton* listen_to;	
		
		// input
		QFormLayout* label_line_edit_ip;
		QFormLayout* label_line_edit_port;
		QLabel* ip_label;
		QLabel* port_label;
		QLineEdit* edit_ip;
		QLineEdit* edit_port;
		
		// button layout
		QHBoxLayout* button_layout;
		QPushButton* cancel_button;
		QPushButton* task_button;			

		// for line edit
		QString str;
		
		// state machine 
		QStateMachine* state_machine;
		QState* connect_state;
		QState* make_connection_state;

	public:
		std::string ip_address;
		std::string port;
	
	private slots:
		void GetIpAddress();

	private:
		void CreateToolBar();

		void StateMachine();

	public:
		ConnectionDialog();
		~ConnectionDialog() = default;
};

/*
	#######################################
	#									  #
	#	Main Label						  #
	#									  #
	#	###############################   #
	#	# ip address		  		  #   #
	#	###############################   #
	#									  #
	#		     cancel       connect	  #
	#									  #
	#######################################
*/

#endif /* DIALOG_HPP_ */
