#include "level1.h"
#include <cstdlib>
#include "block.h"
using namespace std;

vector<Block*> Level1::createPiece(ifstream& sequence, bool random, int lastBlockCleared){
	vector <Block> newBlocks; 
	srand(seed);
	int randNum = rand();
		
	if(randNum < RAND_MAX/12){
		newBlocks.emplace_back(new SBlock('S' 0, 1));
	}
	else if(randNum < RAND_MAX/12 * 2){
		newBlocks.emplace_back(new ZBlock('Z' 0, 1));
	}
	else if(randNum < RAND_MAX/12 * 4){
		newBlocks.emplace_back(new IBlock('I' 0, 1));
	}	
	else if(randNum < RAND_MAX/12 *6){
		newBlocks.emplace_back(new JBlock('J' 0, 1));
	}
	else if(randNum < RAND_MAX/12 * 8){
		newBlocks.emplace_back(new LBlock('L' 0, 1));
	}
	else if(randNum < RAND_MAX/12 * 10){
		newBlocks.emplace_back(new OBlock('O' 0, 1));
	}
	else{
		newBlocks.emplace_back(new TBlock('T' 0, 1));
	}
	return newBlocks;

}

Level1::Level1(int seed):seed{seed}{}

Level1::~Level1(){}
