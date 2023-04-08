#ifndef DESIGN_HPP_
#define DESIGN_HPP_

#include <iostream>

// Qt
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QFont>
#include <QFontDatabase>
#include <QString>
#include <QHBoxLayout>
#include <QFrame>
#include <QScrollArea>
#include <QScrollBar>

// stl
#include <vector>

class Design
{
private:	
	const char* title = "Chat";

	// resolution
	unsigned short width;
	unsigned short height;

	// font
	int id = QFontDatabase::addApplicationFont(":/Resources/font/static/Nunito-Bold.ttf");
  	QString nunito = QFontDatabase::applicationFontFamilies(id).at(0);

	QFont lbl_font;
	unsigned short lbl_font_size; 

	QFont message_font;
	unsigned short message_font_size; 

	QFont text_edit_font;
	unsigned short text_edit_font_size; 

	QFont dialogs_label_font;

	// data
	int labels_size;
	std::vector<QLabel*> labels;
	std::vector<QHBoxLayout*> h_layouts;

private:
	// labels size
	int GetLabelsSize();

public:
	Design() 
	{
		width = 800;
		height = 600;

		lbl_font = QFont(nunito);
		message_font = QFont(nunito);
		text_edit_font = QFont(nunito);
		dialogs_label_font = QFont(nunito);

		message_font_size = 14;
		message_font.setPixelSize(message_font_size);

		lbl_font_size = 18;
		lbl_font.setPixelSize(lbl_font_size);

		text_edit_font_size = 14;
		text_edit_font.setPixelSize(text_edit_font_size);
	}

	~Design() = default;
		
	// set font, set alignment, set frame style
	QHBoxLayout* MessageEstablishing(std::string&, bool, QScrollArea*);

	// return title
	const char* GetTitle();
		
	// width
	const unsigned short GetWidth();

	// height
	const unsigned short GetHeight(); 

	// set font
	void SetLabelFont(QLabel*);

	void SetTextEditFont(QTextEdit*);

	void SetNunitoLabelFont(QLabel*);

	void SetNunitoLineFont(QLineEdit*);
};

#endif /* DESIGN_HPP_ */
