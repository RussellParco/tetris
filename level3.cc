#include "level3.h"

Block* Level3::createPiece(ifstream& sequence, bool random, int lastBlockCleared){
	vector <Block*> newBlocks; 
	if(random){
		srand(seed);
		int randNum = rand();
	       		
		if(randNum < 2*RAND_MAX/9){
			newBlocks.emplace_back(new SBlock('S', 1, 3);
		}
		else if(randNum < 4*RAND_MAX/9){
			newBlocks.emplace_back(new ZBlock('Z', 1, 3);
		}
		else if(randNum < 5*RAND_MAX/9){
			newBlocks.emplace_back(new IBlock('I', 1, 3));
        	}	
		else if(randNum < 6*RAND_MAX/9){
			newBlocks.emplace_back(new JBlock('J', 1, 3));
        	}
       	 	else if(randNum < 7*RAND_MAX/9){
			newBlocks.emplace_back(new LBlock('L', 1, 3));
        	}
        	else if(randNum < 8*RAND_MAX/9){
			newBlocks.emplace_back(new OBlock('O', 1, 3));
        	}
		else{
			newBlocks.emplace_back(new TBlock('T', 1, 3));
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
}

Level3::Level3(int seed):seed{seed}{}

Level3::~Level3(){}
