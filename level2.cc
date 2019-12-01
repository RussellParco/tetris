#include "level2.h"
#include <cstdlib>
std::vector<Block*> Level2::createPiece(ifstream& sequence, bool random, int lastBlockCleared){
	vector <Block*> newBlocks; 
	if(random){
		srand(seed);
		int randNum = rand();
	       		
		if(randNum < RAND_MAX/12){
			newBlocks.emplace_back(new SBlock('S', 0, 2);
		}
		else if(randNum < 2*RAND_MAX/7{
			newBlocks.emplace_back(new ZBlock('Z', 0, 2);
		}
		else if(randNum < 3*RAND_MAX/7){
			newBlocks.emplace_back(new IBlock('I', 0, 2));
        	}	
		else if(randNum < 4*RAND_MAX/7){
			newBlocks.emplace_back(new JBlock('J', 0, 2));
        	}
       	 	else if(randNum < 5*RAND_MAX/7){
			newBlocks.emplace_back(new LBlock('L', 0, 2));
        	}
        	else if(randNum < 6*RAND_MAX/7){
			newBlocks.emplace_back(new OBlock('O', 0, 2));
        	}
		else{
			newBlocks.emplace_back(new TBlock('T', 0, 2));
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
			newBlocks.emplace_back(new Iblock(nextBlock, 0, 2)); 
		}
		else if (nextBlock == 'L'){
			newBlocks.emplace_back(new Lblock(nextBlock, 0, 2)); 
		}
		else if (nextBlock == 'J'){
			newBlocks.emplace_back(new Jblock(nextBlock, 0, 2)); 
		}
	
		else if (nextBlock == 'O'){
			newBlocks.emplace_back(new Oblock(nextBlock, 0, 2));
		}
 
		else if (nextBlock == 'S'){
			newBlocks.emplace_back(new Sblock(nextBlock, 0, 2)); 
		}
	
		else if (nextBlock == 'Z'){
			newBlocks.emplace_back(new Zblock(nextBlock, 0, 2)); 
		}
		else{
			newBlocks.emplace_back(new Tblock(nextBlock, 0, 2)); 
		}
	}


}

Level2::Level2(int seed):seed{seed}{}

Level2::~Level2(){}
