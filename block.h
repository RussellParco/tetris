#ifndef BLOCK
#define BLOCK 
#include "board.h"



class Block {

	vector<vector< Cell>> cells;
	int weight;
	int level;
	char type;

	public:
		rotate(int num);
		drop();
		right;
		left;
		int getScore();	


}; 

//TODo EVERYTHING 








#endif
