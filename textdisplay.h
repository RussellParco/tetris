#ifndef TEXTDISPLAY
#define TEXTDISPLAY
#include "display.h"


class TextDisplay{

	char theDisplay[18 * 11];
			
	public:
		TextDisplay;
		void render() override;
		void updateDisplay() override;

};

#endif 
