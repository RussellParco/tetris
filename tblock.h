#ifndef TBLOCK 
#define TBLOCK
#include "block.h"

class Tblock: public Block{

	public:
	
	Tblock(char type, int weight = 0);
	void down() override;
	void rotate(string type) override;
	void right() override;
	void left() override;
	int getScore() override;
	std::vector<Cell> getCells() override;
};


#endif 
