#include "level0.h"

	createPiece(&ifstream sequence, bool random, int lastBlockCreated){
		char nextBlock;
		sequence >> nextBlock;
		return new Block(nextBlock); 
	}
