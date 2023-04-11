#include "include/design.hpp"

/* 
	sent_received 
	0 - sent
	1 - received 
*/
QHBoxLayout* Design::MessageEstablishing(std::string& label_message, bool sent_received, QScrollArea* scroll_area)
{
	int space_index = -1;

	for (unsigned int symb = 0, message_size = 0; symb != label_message.size(); symb++, message_size++)
	{
		if (label_message[symb] == '\n')
		{
			message_size = 0;
			space_index = -1;
		}
		else if (message_size == 40)
		{
			message_size = 0;	
			if (space_index == -1)
			{
				label_message.insert(symb, "\n");
			}
			else
			{
				label_message[space_index] = '\n';
				space_index = -1;
			}
		}
		else
		{
			if (label_message[symb] == ' ')
				space_index = symb;
		}
	}

	// create label
	h_layouts.push_back(new QHBoxLayout);
	labels.push_back(new QLabel(QString::fromStdString(label_message)));

	labels_size = GetLabelsSize();

	labels[labels_size]->setContentsMargins(20, 10, 0, 0);
	labels[labels_size]->setAlignment(Qt::AlignLeft);

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

	labels[labels_size]->setFixedSize(labels[labels_size]->sizeHint().width() + 20,
					  labels[labels_size]->sizeHint().height() + 10);

	h_layouts[labels_size]->addWidget( labels[labels_size] );

	// scroll bar to bottom
	scroll_area->verticalScrollBar()->setMaximum( scroll_area->height() + labels[labels_size]->sizeHint().height() + 20 );
	scroll_area->verticalScrollBar()->setValue(scroll_area->verticalScrollBar()->maximum());

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
