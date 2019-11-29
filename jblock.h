#ifndef JBLOCK 
#define JBLOCK
#include "block.h"

class Jblock: public Block{

	public:
	
	Jblock(char type, int weight = 0, int level = 0);
	void down();
	void rotate(std::string type);
	void right();
	void left();
	int getScore();
	std::vector<Cell> getCells();
};


#endif 
