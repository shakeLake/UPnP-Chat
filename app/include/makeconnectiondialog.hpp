#ifndef MCDIALOG_HPP_
#define MCDIALOG_HPP_

// i / o
#include <iostream>

// qt / application
#include <QApplication>
#include <QDialog>

// qt / layouts
#include <QVBoxLayout>
#include <QHBoxLayout>

// qt gui
#include <QFormLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QToolBar>

class MakeConnectionDialog : public QDialog
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
		QLabel* ip_text;
		QLabel* port_label;
		QLineEdit* edit_port;
		
		// button layout
		QHBoxLayout* button_layout;
		QPushButton* cancel_button;
		QPushButton* task_button;			

		// for line edit
		QString str;
		
	public:
		bool accept_message = false;
		std::string port;

	public:
		MakeConnectionDialog();
		~MakeConnectionDialog() = default;
};

#endif /* MCDIALOG_HPP_ */
