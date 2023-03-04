#include "include/design.hpp"

/* 
	sent_received 
	0 - sent
	1 - received 
*/
QLabel* Design::LabelEstablish(std::string label_message, bool sent_received)
{
	static int incr = -1;
	incr += 1;

	// create label
	labels.push_back(new QLabel(QString::fromStdString(label_message)));
	
	if (sent_received)
		labels[incr]->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
	else
		labels[incr]->setAlignment(Qt::AlignRight | Qt::AlignBottom);

	labels[incr]->setFont(font);
	labels[incr]->setFrameStyle(QFrame::Panel | QFrame::Sunken);

	return labels[incr];
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
