#ifndef SBLOCK 
#define SBLOCK
#include "block.h"

class Sblock: public Block{

	public:
	
	Sblock(char type,int width= 3, int height = 2, int weight =0, int level = 0);
};


#endif 
