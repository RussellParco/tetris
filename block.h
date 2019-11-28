#ifndef BLOCK
#define BLOCK 
#include "cell.h"
#include "coord.h"
#include <string>

class Block {

	std::vector<Cell> cells(4);
	int weight;
	int level;
	char type;

	public:
	//	Block(char type, int weight = 0);
		virtual void rotate(string type);
		virtual void down();
		virtual void right();
		virtual void left();
		virtual int getScore();	


}; 


#endif
