#ifndef OBLOCK 
#define OBLOCK
#include "block.h"

class Oblock: public Block{

	public:
	
	Oblock(char type, int weight = 0);
	void down() override;
	void rotate(string type) override;
	void right() override;
	void left() override;
	int getScore() override;
	std::vector<Cell> getCells() override;
};


#endif 
