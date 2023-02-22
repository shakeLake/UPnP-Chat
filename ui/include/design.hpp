// Qt
#include <QLabel>
#include <QFont>

class Design
{
	private:	
		const char* title = "UpNpChat";

		// resolution
		const unsigned short width = 480;
		const unsigned short height = 640;

		// font
		constexpr unsigned short font_size = 17; 

		QFont font;
		//font.setPixelSize(font_size);

		// data
		std::vector<QLabel*> labels;
	private:
		// vec::label::push_back( new QLabel )
		void CreateLabel();
	public:
		Design();
		~Design() = default;
		
		// set font, set alignment, set frame style
		QLabel* LabelEstablishing();
		
		// return title
		const char* GetTitle();
		
		// width
		const unsigned short GetWidth();

		//height
		const unsigned short GetHeight(); 
};
