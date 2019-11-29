#ifndef ZBLOCK 
#define ZBLOCK
#include "block.h"

class Zblock: public Block{

	public:
	
	Zblock(char type, int weight = 0, int level = 0);
	void rotate(std::string type);
	void down();
	void right();
	void left();
	int getScore();
	std::vector<Cell> getCells();
};


#endif 
