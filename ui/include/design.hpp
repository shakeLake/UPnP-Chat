// Qt
#include <QLabel>
#include <QFont>

// stl
#include <vector>

class Design
{
	private:	
		const char* title = "UpNpChat";

		// resolution
		const unsigned short width = 900;
		const unsigned short height = 600;

		// font
		QFont font;
		const unsigned short font_size = 17; 

		// data
		std::vector<QLabel*> labels;

	public:
		Design() 
		{
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
