#ifndef UI_HPP_
#define UI_HPP_

// I / O
#include <iostream>

class UserInterface : public QMainWindow
{
	Q_OBJECT

	private:
		// toolbar
			QToolBar* tool_bar;
			QPushButton* disconnect_button;
			QLabel* ip_label;	

		// chat widgets
			QPushButton* send_buton;
			QTextEdit* main_Text_field;
			QLable* message;		

	private:
		// toolbar
			void CreateToolBar();
	public:
		UserInterface();
		~UserInterface() = default;
};

#endif /* UI_HPP *\
