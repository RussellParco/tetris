#ifndef CELL
#define CELL
#include "coord.h"
class Cell{
	Coord current;		
	char content;
	
	public:
	Cell(Coord current, char content);
	const char getContent();
	void setContent(char letter);
	const Coord getCoord();
	void setCoord(Coord temp);
			
	};

#endif
