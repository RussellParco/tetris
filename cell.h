#ifndef CELL
#define CELL
#include "coord.h"

	class Cell{
		Coord current;		
		char content;
		
		public:
			Cell(Coord current, char content);
			char getContent();
			void setContent(char letter);
			Coord getCoord();
			void setCoord(Coord temp);
			
	};

#endif
