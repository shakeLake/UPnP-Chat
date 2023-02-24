#ifndef DIALOG_HPP_
#define DIALOG_HPP_

#include <iostream>

#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>

class ConnectionDialog : public QDialog
{
	Q_OBJECT
	
	private:
		QLabel* main_label;
		QLineEdit* edit_ip;
		QPushButton* cancel_button;
		QPushButton* connect_button;			

		// for line edit
		QString str;

	public:
		std::string ip_address;
	
	private:
		void GetIpAddress();

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
