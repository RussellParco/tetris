#ifndef BLOCK
#define BLOCK 
#include "cell.h"
#include "coord.h"
#include <string>
#include <vector>
class Block {
	protected:
		std::vector<Cell> cells;
		char type;
		int width;
		int height;	
		int weight;
		int level;
	public:
		Block(char type,int width, int height, int weight=0, int level = 0);
		virtual void rotate(std::string type);
		virtual void down();
		virtual void right();
		virtual void left();
		virtual int getScore();	
		virtual bool remove(int cellindex);
		virtual std::vector<Cell> getCells();
		virtual ~Block();
		virtual int getHeight();
		virtual int  getWidth();
}; 


#endif
