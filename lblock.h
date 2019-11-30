#ifndef LBLOCK 
#define LBLOCK
#include "block.h"

class Lblock: public Block{

	public:
	
	Lblock(char type, int width=3, int height = 2, int weight = 0, int level =0);
};


#endif 
