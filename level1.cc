#include "level1.h"
#include <cstdlib>
#include "block.h"

using namespace std;

vector<Block*> Level1::createPiece(ifstream& sequence, bool random, int lastBlockCleared){
	vector <Block*> newBlocks; 
	int randNum = rand();
	std::cout << randNum;
	if(randNum < RAND_MAX/12){
		newBlocks.emplace_back(new Sblock('S', 0, 1));
	}
	else if(randNum < RAND_MAX/12 * 2){
		newBlocks.emplace_back(new Zblock('Z', 0, 1));
	}
	else if(randNum < RAND_MAX/12 * 4){
		newBlocks.emplace_back(new Iblock('I', 0, 1));
	}	
	else if(randNum < RAND_MAX/12 *6){
		newBlocks.emplace_back(new Jblock('J', 0, 1));
	}
	else if(randNum < RAND_MAX/12 * 8){
		newBlocks.emplace_back(new Lblock('L', 0, 1));
	}
	else if(randNum < RAND_MAX/12 * 10){
		newBlocks.emplace_back(new Oblock('O', 0, 1));
	}
	else{
		newBlocks.emplace_back(new Tblock('T', 0, 1));
	}
	return newBlocks;

}

Level1::Level1(){}

Level1::~Level1(){}
