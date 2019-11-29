#ifndef BLOCK
#define BLOCK 
#include "cell.h"
#include "coord.h"
#include <string>
#include <vector>

class Block {
	protected:
		std::vector<Cell> cells;
		int weight;
		int level;
		char type;

	public:
		Block(char type, int weight, int level);
		virtual void rotate(std::string type);
		virtual void down();
		virtual void right();
		virtual void left();
		virtual int getScore();	
		virtual std::vector<Cell> getCells();
		virtual ~Block();
}; 


#endif
