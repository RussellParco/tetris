#ifndef OBLOCK 
#define OBLOCK
#include "block.h"

class Oblock: public Block{

	public:
	
	Oblock(char type, int weight = 0, int level = 0 );
	void down();
	void rotate(std::string type);
	void right();
	void left();
	int getScore();
	std::vector<Cell> getCells();
};


#endif 
