#ifndef ERRORDIALOG_HPP_
#define ERRORDIALOG_HPP_

// qt
#include <QDialog>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QPushButton>

class ErrorDialog : public QDialog
{
private:
	QWidget* center_widget;
	QVBoxLayout* main_layout;	

	QLabel* error_message;

	QPushButton* okay_button;

public:
	ErrorDialog(const std::string&);
	~ErrorDialog() = default;
};

#endif /* ERRORDIALOG_HPP_ */
