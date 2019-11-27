#ifndef SBLOCK 
#define SBLOCK
#include "block.h"

class Sblock: public Block{

	public:
	
	Sblock(char type, int weight =0);
	void down() override;
	void rotate(string type) override;
	void right() override;
	void left() override;
	int getScore() override;

};


#endif 
