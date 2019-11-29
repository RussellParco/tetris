#ifndef CELL
#define CELL
#include "coord.h"
class Cell{
	Coord current;		
	char content;
	
	public:
	Cell(Coord current = {0,0} , char content = 0);
	const char getContent();
	void setContent(char letter);
	Coord getCoord();
	void setCoord(Coord temp);
			
	};

#endif
