#ifndef TBLOCK 
#define TBLOCK
#include "block.h"

class Tblock: public Block{

	public:
	
	Tblock(char type, int weight = 0, int level = 0);
	void down();
	void rotate(std::string type);
	void right();
	void left();
	int getScore();
	std::vector<Cell> getCells();
};


#endif 
