#include "level4.h"

std::vector<Block*> Level4::createPiece(ifstream& sequence, bool random, int lastBlockCleared){
	vector <Block*> newBlocks; 
	if(lastBlockCleared > 0 && lastBlockCleared % 5 == 0){	
       		newBlocks.emplace_back(new Forceblock(1, 4));
	}
	if(random){
		int randNum = rand();
	       		
		if(randNum < RAND_MAX/12){
			newBlocks.emplace_back(new Sblock('S', 1, 4));
		}
		else if(randNum < RAND_MAX/7 *2){
			newBlocks.emplace_back(new Zblock('Z', 1, 4));
		}
		else if(randNum < RAND_MAX/7 * 3){
			newBlocks.emplace_back(new Iblock('I', 1, 4));
        	}	
		else if(randNum < RAND_MAX/7*4){
			newBlocks.emplace_back(new Jblock('J', 1, 4));
        	}
       	 	else if(randNum < RAND_MAX/7*5){
			newBlocks.emplace_back(new Lblock('L', 1, 4));
        	}
        	else if(randNum < RAND_MAX/7*6){
			newBlocks.emplace_back(new Oblock('O', 1, 4));
        	}
		else{
			newBlocks.emplace_back(new Tblock('T', 1, 4));
		}
	}
	else{
		char nextBlock;
		sequence >> nextBlock;
		
		if(sequence.eof()){
            		sequence.clear();
               		sequence.seekg(0, sequence.beg);
             		sequence >> nextBlock;
      		}

		if (nextBlock == 'I'){
			newBlocks.emplace_back(new Iblock(nextBlock, 1, 4)); 
		}
		else if (nextBlock == 'L'){
			newBlocks.emplace_back(new Lblock(nextBlock, 1, 4)); 
		}
		else if (nextBlock == 'J'){
			newBlocks.emplace_back(new Jblock(nextBlock, 1, 4)); 
		}
	
		else if (nextBlock == 'O'){
			newBlocks.emplace_back(new Oblock(nextBlock, 1, 4));
		}
 
		else if (nextBlock == 'S'){
			newBlocks.emplace_back(new Sblock(nextBlock, 1, 4)); 
		}
	
		else if (nextBlock == 'Z'){
			newBlocks.emplace_back(new Zblock(nextBlock, 1, 4)); 
		}
		else{
			newBlocks.emplace_back(new Tblock(nextBlock, 1, 4)); 
		}
	}
	return newBlocks;
}

Level4::Level4(){};

Level4::~Level4(){}
