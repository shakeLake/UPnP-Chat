// Qt
#include <QLabel>
#include <QFont>
#include <QString>

// stl
#include <vector>

class Design
{
	private:	
		const char* title = "UpNpChat";

		// resolution
		unsigned short width;
		unsigned short height;

		// font
		QFont font;
		unsigned short font_size; 

		// data
		std::vector<QLabel*> labels;

	public:
		Design() 
		{
			width = 900;
			height = 600;

			font_size = 17;

			font.setPixelSize(font_size);	
		}

		~Design() = default;
		
		// set font, set alignment, set frame style
		QLabel* LabelEstablish(std::string, bool);

		// return title
		const char* GetTitle();
		
		// width
		const unsigned short GetWidth();

		// height
		const unsigned short GetHeight(); 
};
