#ifndef UI_HPP_
#define UI_HPP_

// I / O
#include <iostream>

// Qt
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>
#include <QLabel>
#include <QTextEdit>

class UserInterface : public QMainWindow
{
	Q_OBJECT

	private:
		// toolbar
			QToolBar* toolBar;
			QPushButton* disconnectButton;
			QLabel* ip;	

		// chat widgets
			QPushButton* sendButon;
			QTextEdit* mainTextField;
			// QLable* Message;		
	private:
		// toolbar
			void CreateToolBar();
	public:
		UserInterface();
		~UserInterface() = default;
};

#endif /* UI_HPP *\
