#ifndef UI_HPP_
#define UI_HPP_

// I / O
#include <iostream>

// qt
#include <QApplication>
#include <QMainWindow>

// widgets
#include <QToolBar>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>

class UserInterface : public QMainWindow
{
	Q_OBJECT

	private:
		// toolbar
			QToolBar* tool_bar;

		// chat widgets
			QPushButton* send_buton;
			QTextEdit* main_Text_field;
			QLabel* message;		

	private:
		// toolbar
			void CreateToolBar();
	public:
		UserInterface();
		~UserInterface() = default;
};

#endif /* UI_HPP */
