#ifndef ZBLOCK 
#define ZBLOCK
#include "block.h"

class Zblock: public Block{

	public:
	
	Zblock(char type, int weight = 0);
	void rotate(string type) override;
	void down() override;
	
	void right() override;
	void left() override;
	int getScore() override;
	std::vector<Cell> getCells() override;
};


#endif 
