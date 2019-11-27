#ifndef LBLOCK 
#define LBLOCK
#include "block.h"

class Lblock: public Block{

	public:
	
	Lblock(char type, int weight = 0);
	void down() override;
	void rotate(string type) override;
	void right() override;
	void left() override;
	int getScore() override;

};


#endif 
