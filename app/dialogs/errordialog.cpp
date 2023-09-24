#include "include/errordialog.hpp"

ErrorDialog::ErrorDialog(const std::string& er_msg)
{
	setWindowTitle("Error dialog");
	setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);	
	resize(385, 90);

	center_widget = new QWidget(this);
	center_widget->setFixedSize(385, 90);
	setStyleSheet("background-color: white");

	main_layout = new QVBoxLayout(center_widget);

	warning_icon = new QPushButton;
	warning_icon->setIcon(QIcon(":/Resources/pics/warning.png"));
	warning_icon->setStyleSheet("border: none");
	warning_icon->setIconSize(QSize(40, 40));

	error_message = new QLabel(QString::fromStdString(er_msg));	
	style.SetNunitoLabelFont(error_message);

	icon_label = new QFormLayout();
	icon_label->addRow(warning_icon, error_message);

	button_layout = new QHBoxLayout();
	button_layout->setAlignment(Qt::AlignRight);

	okay_button = new QPushButton("Okay");
	okay_button->setFixedSize(125, 24);
	okay_button->setStyleSheet("background-color: #161C32;"
								"color: white;"
								"border-radius: 5px");

	button_layout->addWidget(okay_button);

	connect(okay_button, &QPushButton::released, this, [this]{ reject(); });

	main_layout->addLayout(icon_label);
	main_layout->addLayout(button_layout);
}