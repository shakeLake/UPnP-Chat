#include "include/design.hpp"

/* 
	sent_received 
	0 - sent
	1 - received 
*/
QLabel* Design::MessageEstablishing(std::string& label_message, bool sent_received)
{
	// create label
	labels.push_back(new QLabel(QString::fromStdString(label_message)));
	
	labels_size = GetLabelsSize();

	if (sent_received)
	{
		labels[labels_size]->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
		//labels[labels_size]->setContentsMargins(0, 0, 500, 0);
	}
	else
	{
		labels[labels_size]->setAlignment(Qt::AlignRight | Qt::AlignBottom);
		//labels[labels_size]->setContentsMargins(500, 0, 0, 0);
	}

	labels[labels_size]->setFont(message_font);
	labels[labels_size]->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	labels[labels_size]->setFixedHeight(30);

	return labels[labels_size];
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
