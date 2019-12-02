#include "level3.h"

std::vector<Block*> Level3::createPiece(ifstream& sequence, bool random, int lastBlockCleared){
	vector <Block*> newBlocks; 
	if(random){
		int randNum = rand();
	       		
		if(randNum < RAND_MAX/9 *2){
			newBlocks.emplace_back(new Sblock('S', 1, 3));
		}
		else if(randNum < RAND_MAX/9 * 4){
			newBlocks.emplace_back(new Zblock('Z', 1, 3));
		}
		else if(randNum < RAND_MAX/9 * 5){
			newBlocks.emplace_back(new Iblock('I', 1, 3));
        	}	
		else if(randNum < RAND_MAX/9 * 6){
			newBlocks.emplace_back(new Jblock('J', 1, 3));
        	}
       	 	else if(randNum < RAND_MAX/9 * 7){
			newBlocks.emplace_back(new Lblock('L', 1, 3));
        	}
        	else if(randNum < RAND_MAX/9 * 8){
			newBlocks.emplace_back(new Oblock('O', 1, 3));
        	}
		else{
			newBlocks.emplace_back(new Tblock('T', 1, 3));
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
			newBlocks.emplace_back(new Iblock(nextBlock, 1, 3)); 
		}
		else if (nextBlock == 'L'){
			newBlocks.emplace_back(new Lblock(nextBlock, 1, 3)); 
		}
		else if (nextBlock == 'J'){
			newBlocks.emplace_back(new Jblock(nextBlock, 1, 3)); 
		}
	
		else if (nextBlock == 'O'){
			newBlocks.emplace_back(new Oblock(nextBlock, 1, 3));
		}
 
		else if (nextBlock == 'S'){
			newBlocks.emplace_back(new Sblock(nextBlock, 1, 3)); 
		}
	
		else if (nextBlock == 'Z'){
			newBlocks.emplace_back(new Zblock(nextBlock, 1, 3)); 
		}
		else{
			newBlocks.emplace_back(new Tblock(nextBlock, 1, 3)); 
		}
	}
	return newBlocks;

}

Level3::Level3(){}

Level3::~Level3(){}
