#ifndef IBLOCK 
#define IBLOCK
#include "block.h"

class Iblock: public Block{

	public:
	Iblock(char type, int weight = 0, int level = 0);
	void down();
	void rotate(std::string type);
	void right();
	void left();
	int getScore();
	std::vector<Cell> getCells();
};


#endif 
