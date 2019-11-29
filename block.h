#ifndef BLOCK
#define BLOCK 
#include "cell.h"
#include "coord.h"
#include <string>
#include <vector>

class Block {

	std::vector<Cell> cells;
	int weight;
	int level;
	char type;

	public:

		virtual void rotate(std::string type);
		virtual void down();
		virtual void right();
		virtual void left();
		virtual int getScore();	
		virtual std::vector<Cell> getCells();

}; 


#endif
