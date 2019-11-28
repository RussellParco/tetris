#ifndef CELL
#define CELL
#include "coord.h"
#include "block.h"

	class Cell{
		Coord current;		
		char content;
		Block * block;
		
		public:
			Block * getBlock();
			void setBlock();
			char getContent();
			void setContent();
			void getCoord;

	};

#endif
