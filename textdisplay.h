#ifndef TEXTDISPLAY
#define TEXTDISPLAY
#include "display.h"


class TextDisplay{

	vector<char> theDisplay;
		
	public:
		void render() override;
		void updateDisplay() override;

};

#endif 
