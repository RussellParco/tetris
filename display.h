#ifndef DISPLAY
#define	DISPLAY
#include "game.h"


class Display{
	int height;
	int width;
	
	public:
		virtual render() = 0;
		virtual updateDisplay(char content, int x, int y, Board const * src) = 0;
		virtual updateRows(int row1, int row2, Board const * src) = 0;
};




#endif 
