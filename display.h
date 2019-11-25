#ifndef DISPLAY
#define	DISPLAY
#include "game.h"


class Display{
	int height;
	int width;
	
	public:
		virtual render() = 0;
		virtual updateDisplay();
	

};




#endif 
