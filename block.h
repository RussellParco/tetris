#ifndef BLOCK
#define BLOCK 
#include "cell.h"
#include "coord.h"
#include <string>

class Block {

	Cell cells[4];
	int weight;
	int level;
	char type;

	public:

		virtual void rotate(std::string type);
		virtual void down();
		virtual void right();
		virtual void left();
		virtual int getScore();	
		virtual void remove(int cellindex);

}; 


#endif
