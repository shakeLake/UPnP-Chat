// Qt
#include <QLabel>
#include <QFont>
#include <QFontDatabase>
#include <QString>

// stl
#include <vector>

class Design
{
private:	
	const char* title = "Chat";

	// resolution
	unsigned short width;
	unsigned short height;

	// fonts
	QFont message_font;
	unsigned short message_font_size; 

	QFont label_font;

	// data
	int labels_size;
	std::vector<QLabel*> labels;

private:
	// labels size
	int GetLabelsSize();

public:
	Design() 
	{
		width = 900;
		height = 600;

		message_font_size = 17;
		message_font.setPixelSize(message_font_size);	
	}

	~Design() = default;
		
	// set font, set alignment, set frame style
	QLabel* MessageEstablishing(std::string&, bool);
	
	// set font, set alignment, set frame style
	QLabel* MakeLabel(unsigned short, std::string&);

	// return title
	const char* GetTitle();
		
	// width
	const unsigned short GetWidth();

	// height
	const unsigned short GetHeight(); 
};
