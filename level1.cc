#include "level1.h"
#include <cstdlib>
using namespace std;

vector<Block*> Level1::createPiece(ifstream& sequence, bool random, int lastBlockCleared){
	vector <Block*> newBlocks; 
	if(random){
		srand(seed);
		int randNum = rand();
	       		
		if(randNum < RAND_MAX/12){
			newBlocks.emplace_back(new SBlock('S' 0, 1));
		}
		else if(randNum < 2*RAND_MAX/12){
			newBlocks.emplace_back(new ZBlock('Z' 0, 1));
		}
		else if(randNum < 4*RAND_MAX/12){
			newBlocks.emplace_back(new IBlock('I' 0, 1));
        	}	
		else if(randNum < 6*RAND_MAX/6){
			newBlocks.emplace_back(new JBlock('J' 0, 1));
        	}
       	 	else if(randNum < 8*RAND_MAX/12){
			newBlocks.emplace_back(new LBlock('L' 0, 1));
        	}
        	else if(randNum < 10*RAND_MAX/12){
			newBlocks.emplace_back(new OBlock('O' 0, 1));
        	}
		else{
			newBlocks.emplace_back(new TBlock('T' 0, 1));
		}
	}
	else{
		char nextBlock;
		sequence >> nextBlock;
		if (nextBlock == 'I'){
			newBlocks.emplace_back(new Iblock(nextBlock 0, 1)); 
		}
		else if (nextBlock == 'L'){
			newBlocks.emplace_back(new Lblock(nextBlock 0, 1)); 
		}
		else if (nextBlock == 'J'){
			newBlocks.emplace_back(new Jblock(nextBlock 0, 1)); 
		}
	
		else if (nextBlock == 'O'){
			newBlocks.emplace_back(new Oblock(nextBlock 0, 1));
		}
 
		else if (nextBlock == 'S'){
			newBlocks.emplace_back(new Sblock(nextBlock 0, 1)); 
		}
	
		else if (nextBlock == 'Z'){
			newBlocks.emplace_back(new Zblock(nextBlock 0, 1)); 
		}
		else{
			newBlocks.emplace_back(new Tblock(nextBlock 0, 1)); 
		}
	}

       
}

Level1::Level1(){}

Level1::~Level1(){}
