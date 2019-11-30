#ifndef IBLOCK 
#define IBLOCK
#include "block.h"

class Iblock: public Block{

	public:
	Iblock(char type, int width=4, int height=1, int weight = 0, int level = 0);
};


#endif 
