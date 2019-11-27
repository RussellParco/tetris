#ifndef IBLOCK 
#define IBLOCK
#include "block.h"

class Iblock: public Block{

	public:
	
	Iblock(char type, int weight = 0);
	void down() override;
	void rotate(string type) override;
	void right() override;
	void left() override;
	int getScore() override;

}


#endif 
