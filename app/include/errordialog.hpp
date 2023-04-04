#ifndef ERRORDIALOG_HPP_
#define ERRORDIALOG_HPP_

// design
#include "design.hpp"

// qt
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QIcon>
#include <QString>

// layout
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>

class ErrorDialog : public QDialog
{
private:
	Design style;

	QWidget* center_widget;
	QVBoxLayout* main_layout;	

	QFormLayout* icon_label;
	QPushButton* warning_icon;
	QLabel* error_message;

	QHBoxLayout* button_layout;
	QPushButton* okay_button;

public:
	ErrorDialog(const std::string&);
	~ErrorDialog() = default;
};

#endif /* ERRORDIALOG_HPP_ */
