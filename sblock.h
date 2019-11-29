#ifndef SBLOCK 
#define SBLOCK
#include "block.h"

class Sblock: public Block{

	public:
	
	Sblock(char type, int weight =0, int level = 0);
	void down();
	void rotate(std::string type);
	void right();
	void left();
	int getScore();
	std::vector<Cell> getCells();
};


#endif 
