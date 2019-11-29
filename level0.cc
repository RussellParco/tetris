#include "level0.h"

Level0::Level0(){}

Block * Level0::createPiece(std::ifstream & sequence, bool random, int lastBlockCreated){
		char nextBlock;
		sequence >> nextBlock;
		if (nextBlock == 'I'){
			return new Iblock(nextBlock); 
		}
		else if (nextBlock == 'L'){
			return new Lblock(nextBlock); 
		}
		else if (nextBlock == 'J'){
			return new Jblock(nextBlock); 
		}
	
		else if (nextBlock == 'O'){
			return new Oblock(nextBlock);
		}
 
		else if (nextBlock == 'S'){
			return new Sblock(nextBlock); 
		}
	
		else if (nextBlock == 'Z'){
			return new Zblock(nextBlock); 
		}
		else{
			return new Tblock(nextBlock); 
		}
}

Level0::~Level0(){}
