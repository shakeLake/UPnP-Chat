#ifndef ALREADYOPENED_HPP_
#define ALREADYOPENED_HPP_

// i / o
#include <iostream>

// design
#include "../../include/design.hpp"

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

class AlreadyOpenedDialog : public QDialog
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
	QFormLayout* label_line_edit_port;
	QLabel* port_label;
	QLineEdit* edit_port;
		
	// button layout
	QHBoxLayout* button_layout;
	QPushButton* cancel_button;
	QPushButton* task_button;			

	// for line edit
	QString port_str;
		
public:
	std::string port;
	
public slots:
	void GetPort();

public:
	AlreadyOpenedDialog();
	~AlreadyOpenedDialog() = default;
};

#endif /* ALREADYOPENED_HPP_  */
