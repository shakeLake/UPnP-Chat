#include "include/design.hpp"

/* 
	sent_received 
	0 - sent
	1 - received 
*/
QHBoxLayout* Design::MessageEstablishing(std::string& label_message, bool sent_received)
{
	std::cout << "MsgEst" << label_message << std::endl;

	// create label
	h_layouts.push_back(new QHBoxLayout);
	labels.push_back(new QLabel(QString::fromStdString(label_message)));

	labels_size = GetLabelsSize();

	labels[labels_size]->setAlignment(Qt::AlignCenter);

	// message analysis


	labels[labels_size]->setFixedSize(300, 40);	

	labels[labels_size]->setStyleSheet("background: #FFFCF9;"
									   "border-radius: 10px;");

	if (sent_received)
	{
		h_layouts[labels_size]->setAlignment(Qt::AlignLeft);
	}
	else
	{
		h_layouts[labels_size]->setAlignment(Qt::AlignRight);
	}

	labels[labels_size]->setFont(message_font);

	h_layouts[labels_size]->addWidget( labels[labels_size] );

	return h_layouts[labels_size];
}

void Design::SetLabelFont(QLabel* lbl)
{
	lbl->setStyleSheet("color: #0D0C1C");
	lbl->setFont(lbl_font);
}

void Design::SetTextEditFont(QTextEdit* te)
{
	te->setStyleSheet("color: #0D0C1C");
	te->setFont(text_edit_font);
}

void Design::SetNunitoLabelFont(QLabel* lbl)
{
	lbl->setStyleSheet("color: #0D0C1C");
	lbl->setFont(text_edit_font);
}

void Design::SetNunitoLineFont(QLineEdit* le)
{
	le->setFont(text_edit_font);
}

int Design::GetLabelsSize()
{
	return labels.size() - 1;
}

const char* Design::GetTitle()
{
	return title;
}

const unsigned short Design::GetWidth()
{
	return width;
}

const unsigned short Design::GetHeight()
{
	return height;
}
