#ifndef JBLOCK 
#define JBLOCK
#include "block.h"

class Jblock: public Block{

	public:
	
	Jblock(char type, int weight = 0);
	void down() override;
	void rotate(string type) override;
	void right() override;
	void left() override;
	int getScore() override;
	std::vector<Cell> getCells() override;
}


#endif 
