#include "include/acceptdialog.hpp"

AcceptDialog::AcceptDialog(std::string& inv_code)
{
	setWindowTitle("Trying...");
	resize(350, 150);

	center_widget = new QWidget(this);
	main_layout = new QVBoxLayout(center_widget);
	
	invite_code = new QLabel(QString::fromStdString(inv_code));
	waiting_label = new QLabel("waiting...");
}
