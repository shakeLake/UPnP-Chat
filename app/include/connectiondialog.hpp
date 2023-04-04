#ifndef CDIALOG_HPP_
#define CDIALOG_HPP_

// i / o
#include <iostream>

// design
#include "design.hpp"

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

class ConnectionDialog : public QDialog
{
	Q_OBJECT
	
private:
	Design style;

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

	// for IP line edit
	QString ip_str;
		
	// for IP line edit
	QString port_str;

public:
	std::string ip_address;
	std::string port;

private slots:
	void GetIpAddressAndPort();

private:
	void CreateToolBar();

public:
	ConnectionDialog();
	~ConnectionDialog() = default;
};

#endif /* CDIALOG_HPP_ */
