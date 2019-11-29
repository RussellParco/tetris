#ifndef LBLOCK 
#define LBLOCK
#include "block.h"

class Lblock: public Block{

	public:
	
	Lblock(char type, int weight = 0, int level =0);
	void down();
	void rotate(std::string type);
	void right();
	void left();
	int getScore();
	std::vector<Cell> getCells();
};


#endif 
