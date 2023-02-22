#ifndef DIALOG_HPP_
#define DIALOG_HPP_

#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ConnectionDialog : public QDialog
{
	Q_OBJECT
	
	private:
		QLabel* main_label;
		QLineEdit* edit_ip;
		QPushButton* cancel_button;
		QPushButton* connect_button;		
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
