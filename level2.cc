#include "level2.h"
#include <cstdlib>
std::vector<Block*> Level2::createPiece(ifstream& sequence, bool random, int lastBlockCleared){
	vector <Block*> newBlocks; 
	int randNum = rand();
		
	if(randNum < RAND_MAX/12){
		newBlocks.emplace_back(new Sblock('S', 0, 2));
	}
	else if(randNum < RAND_MAX/7 * 2){
		newBlocks.emplace_back(new Zblock('Z', 0, 2));
	}
	else if(randNum < RAND_MAX/7 * 3){
		newBlocks.emplace_back(new Iblock('I', 0, 2));
	}	
	else if(randNum < RAND_MAX/7 *4){
		newBlocks.emplace_back(new Jblock('J', 0, 2));
	}
	else if(randNum < RAND_MAX/7 * 5){
		newBlocks.emplace_back(new Lblock('L', 0, 2));
	}
	else if(randNum < RAND_MAX/7 * 6){
		newBlocks.emplace_back(new Oblock('O', 0, 2));
	}
	else{
		newBlocks.emplace_back(new Tblock('T', 0, 2));
	}
	return newBlocks;

}

Level2::Level2(){}

Level2::~Level2(){}
