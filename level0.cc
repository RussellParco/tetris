#include "level0.h"

Level0::Level0(){}

vector<Block*> Level0::createPiece(std::ifstream & sequence, bool random, int lastBlockCreated){
	char nextBlock;
	sequence >> nextBlock;
	if (nextBlock == 'I'){
		newBlocks.emplace_back(new Iblock(nextBlock)); 
	}
	else if (nextBlock == 'L'){
		newBlocks.emplace_back(new Lblock(nextBlock)); 
	}
	else if (nextBlock == 'J'){
		newBlocks.emplace_back(new Jblock(nextBlock)); 
	}
	
	else if (nextBlock == 'O'){
		newBlocks.emplace_back(new Oblock(nextBlock));
	}
 
	else if (nextBlock == 'S'){
		newBlocks.emplace_back(new Sblock(nextBlock)); 
	}
	
	else if (nextBlock == 'Z'){
		newBlocks.emplace_back(new Zblock(nextBlock)); 
	}
	else{
		newBlocks.emplace_back(new Tblock(nextBlock)); 
	}


}
	
Level0::~Level0(){}
