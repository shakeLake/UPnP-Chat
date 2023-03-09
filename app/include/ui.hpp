#ifndef UI_HPP_
#define UI_HPP_

// I / O
#include <iostream>

// design
#include "design.hpp"

// qt
#include <QApplication>
#include <QMainWindow>

// des
#include <QPixmap>

// layouts
#include <QVBoxLayout>
#include <QHBoxLayout>

// widgets
#include <QToolBar>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>

class UserInterface : public QMainWindow
{
	Q_OBJECT

	private:
		Design style;

		// toolbar
			QToolBar* tool_bar;
			
			QPixmap connect_to_pixmap;			
			QPushButton* connect_to;
				
			QPixmap make_connection_pixmap;			
			QPushButton* make_connection;

		// chat widgets
			QLabel* info_label;
			QHBoxLayout* input_field_layout;
			QPushButton* send_button;
			QTextEdit* main_text_field;
		
		// message 
			QVBoxLayout* message_layout;
			QLabel* message;
			QFont font;		

	private:
		// toolbar
			void CreateToolBar();

	public:
		UserInterface();
		~UserInterface() = default;
};

#endif /* UI_HPP */
