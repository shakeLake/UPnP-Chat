#ifndef ACCEPTDIALOG_HPP_
#define ACCEPTDIALOG_HPP_

// qt
#include <QDialog>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>

class AcceptDialog : public QDialog
{
private:
	QWidget* center_widget;
	QVBoxLayout* main_layout;	

	QLabel* waiting_label;	
	QLabel* invite_code;

public:
	AcceptDialog(char*, char*);
	~AcceptDialog() = default;

};

#endif /* ACCEPTDIALOG_HPP_ */
