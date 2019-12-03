#include "board.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
using namespace std;
 
Board::Board(int level, int width, int height, string seq):
	levelint {level}, width{width}, height{height},
	sequence{ifstream(seq)},lastPieceCleared{1}, blindDisplay{0}, 
	randomInd{true}, randSeq{seq}, defaultSeq{seq}
{ 
	grid.resize(height);
	for (int i = 0; i < height; ++i){
    		grid[i].resize(width);		
	}


	for(int i =0; i < width; i++  ){
		for(int j =0; j < height; j++){
			grid[i][j] = 0;
		}
	}
	sequence = ifstream{seq};

	if(levelint == 0){
		this->level = new Level0();
	}else if(levelint == 1){
		this->level = new Level1();
	}else if(levelint == 2){
		this->level = new Level2();
        }else if (levelint == 3){
		this->level = new Level3();
	}else{
		this->level = new Level4();
	}
	vector<Block*> newBlocks= this->level->createPiece(sequence, randomInd, 
			lastPieceCleared);
	blocks.insert(blocks.end(), newBlocks.begin(), newBlocks.end());
	next = this->level->createPiece(sequence, randomInd,
                        lastPieceCleared).back();

}

bool Board::cellsAvailable(std::vector<Cell> exCells, string type, std::vector<vector <bool>> grid,int blockWidth, int blockHeight){
	vector<Cell> testCells(4);
	for(int i =0; i <= 3; i++){
		int x = exCells[i].getCoord().x;
		int y = exCells[i].getCoord().y;
		Coord newCoord {x,y};
		testCells[i].setCoord(newCoord); 
		
	}
	int bottom = testCells[0].getCoord().y;
	int left = testCells[0].getCoord().x;

		for(int i=0; i <= 3; i++){
	
			if(testCells[i].getCoord().y >= bottom){
				bottom = testCells[i].getCoord().y;
			}
		}
		for(int i=0; i <= 3; i++){
			if(testCells[i].getCoord().x <= left){
				left = testCells[i].getCoord().x;
			}
		}

	for(int i =0; i <=3 ; i++){	
		int xnew = testCells[i].getCoord().x - left;
                int ynew = testCells[i].getCoord().y - bottom;
 			
		if(type == "clockwise"){
			int temp = xnew;
			xnew = -1 * ynew;	
			ynew = temp;
			ynew = ynew - blockWidth + 1;
		}
		else{
			int temp = xnew;
			xnew =  ynew;
			ynew = -1 * temp;
			xnew = xnew + blockHeight - 1;
		
		}
		xnew = xnew + left;
		ynew = ynew + bottom;
		Coord newCoord {xnew, ynew};
	
		testCells[i].setCoord(newCoord);
	}

	
 	int x = 0;
	int y = 0;

	for(int i = 0; i <= 3; i++ ){
		
		x = testCells[i].getCoord().x;
		y = testCells[i].getCoord().y;	
		if(x < 0 || x >= width || y < 0 || y >= height || grid[y][x]){
		
			return false;
		}
	}

	return true;	
}


void Board::counterclockwise(){
	Block *recent = blocks.back();
	int height= recent->getHeight();
	int width = recent->getWidth();
	if (cellsAvailable(recent->getCells(), "counterclockwise", this->grid, width, height)){
		for(auto &c : recent->getCells()){
			updateDisplays(' ', c.getCoord());
		}
		
		recent->rotate("counterclockwise");	
		for(auto &c : recent->getCells()){
                        updateDisplays(c.getContent(), c.getCoord());
                }

	}

}

void Board::clockwise(){
	Block *recent = blocks.back();	
	int height= recent->getHeight();
	int width = recent->getWidth();
 	if (cellsAvailable(recent->getCells(), "clockwise", this->grid, width, height)){
		for(auto &c : recent->getCells()){
                        updateDisplays(' ', c.getCoord());
                }
                recent->rotate("clockwise");
                for(auto &c : recent->getCells()){
                        updateDisplays(c.getContent(), c.getCoord());
                }

	}
}

void Board::right(){
	
	Block* activeBlock = blocks.back();
	for(auto &c : activeBlock->getCells()){
		if(c.getCoord().x  == width-1 || grid[c.getCoord().y][c.getCoord().x + 1]){
			return;
		}
	}
	for(auto &c: activeBlock->getCells()){
		updateDisplays(' ', c.getCoord());
	}
	activeBlock->right();
        for(auto &c : activeBlock->getCells()){
                updateDisplays(c.getContent(), c.getCoord());
        }

}

void Board::left(){
	Block* activeBlock = blocks.back();
        for(auto &c : activeBlock->getCells()){
                if(c.getCoord().x == 0 || grid[c.getCoord().y][c.getCoord().x-1]){
                        
			return;
                
		}
	}
	for(auto &c : activeBlock->getCells()){
		updateDisplays(' ', c.getCoord());
	}
	activeBlock->left();
	for(auto &c : activeBlock->getCells()){
		updateDisplays(c.getContent(), c.getCoord());
        }
}

bool Board::heavy(){
	Block *activeBlock = blocks.back();
	vector<Cell> cells = activeBlock->getCells();
	int weight = activeBlock->getWeight();
	for(int i = 0; i < weight; i++){
		Block *activeBlock = blocks.back();
		for(auto c : activeBlock->getCells()){
			if(c.getCoord().y  == height - 1 || 
					grid[c.getCoord().y+1][c.getCoord().x]){
				return false;
			}
		}
		for(auto c : activeBlock->getCells()){
			updateDisplays(' ', c.getCoord());
		}

		activeBlock->down();
		for(auto c : activeBlock->getCells()){
			updateDisplays(c.getContent(), c.getCoord());
		}
	
	
}
return true;
}


void Board::down(){
	Block *activeBlock = blocks.back(); 
        for(auto &c : activeBlock->getCells()){
                if(c.getCoord().y  == height - 1 || grid[c.getCoord().y+1][c.getCoord().x]){
                        return;
                }
	}
	for(auto &c : activeBlock->getCells()){	      
		updateDisplays(' ', c.getCoord());
	}
        
        activeBlock->down();
	for(auto &c : activeBlock->getCells()){
                updateDisplays(c.getContent(), c.getCoord());
        }
}

int Board::drop(){
	bool dropInd = true;
	Block* activeBlock = blocks.back();
        for(auto &c : activeBlock->getCells()){
                updateDisplays(' ', c.getCoord());
        }

	while(dropInd){
		for(auto &c : activeBlock->getCells()){
        		if((c.getCoord().y == height-1) || 
					grid[c.getCoord().y+1][c.getCoord().x]){
				dropInd = false;
				break;
                	}
        	}
		if(dropInd){
        		activeBlock->down();
		}
	}

	for(auto &c : activeBlock->getCells()){
                grid[c.getCoord().y][c.getCoord().x] = 1;
		updateDisplays(c.getContent(), c.getCoord());
        }	
	int rowsCleared = 0;
	for(int y = 0; y < height; y++){
		bool clearRow = true;
		for(int x = 0; x < width; x++){
			if(!grid[y][x]){
				clearRow = false;
				break;
			}
		}
		if(clearRow){
			score += this->clearRow(y);
			dropRows(y);
			rowsCleared++;
		}
	}

	if(rowsCleared > 0){
		score += (rowsCleared + levelint)*
			(rowsCleared + levelint);
		updateDisplaysScore(score);
	}

      	return rowsCleared;
}

void Board::levelup(){
	if(levelint != 4){
		delete level;
		
		if(levelint == 0){
			level = new Level1();
		}else if(levelint == 1){
			level = new Level2();
		}else if(levelint == 2){
			level = new Level3();
			sequence = ifstream{randSeq};
                }else{
			level = new Level4();
			 sequence = ifstream{randSeq};
		}
		levelint++;
		updateDisplaysLevel(levelint);
	}
}

void Board::leveldown(){
	if(levelint != 0){
                delete level;
                if(levelint == 1){
                        level = new Level0() ;
			 sequence = ifstream{defaultSeq};
                }else if(levelint == 2){
                        level = new Level1();
                }else if(levelint == 3){
                        level = new Level2();
                }else{
                        level = new Level3();
			sequence = ifstream{randSeq};
                }
		levelint--;
		updateDisplaysLevel(levelint);
	}
}
void Board::random(){
	randomInd = true;
}

void Board::noRandom(string file){
	randomInd = false;
	randSeq = file;
	if(levelint >=3){
		sequence = ifstream{randSeq};
	}
}

void Board::restart(){
	score = 0;
	for(int x = 0; x < width; x++){
		for(int y = 0; y < height; y++){
			grid[y][x] = 0;
		}
	}

	for(auto &b: blocks){
		delete b;
	}
	blocks.clear();
	if(level == 0){
		sequence = ifstream{defaultSeq};
	}else{
		sequence = ifstream{randSeq};
	}
	lastPieceCleared = 1;
	nextBlock();
}

void Board::dropRows(int row){
	if(row == 0){
		return;
	}

	std::swap(grid[row], grid[row - 1]);
	updateDisplaysSwap(row, row-1);
	dropRows(row-1);
}

int Board::clearRow(int row){
	int blockscore = 0;
	for(auto b = blocks.begin(); b != blocks.end();){
		if((*b)->removeRow(row)){
			blockscore += (*b)->getScore();
			delete *b;
			b = blocks.erase(b);
			lastPieceCleared = 1;
		}else{
			++b;
		}
	}
	for(int i = 0; i <width; i++){
		updateDisplays(' ', {i, row});
		grid[row][i] = 0;
	}
	return blockscore;
}

int Board::getScore(){
	return score;
}

void Board::updateDisplays(char content, Coord c){
	for (auto &ob : displays) ob->update(content, c);
} 

void Board::updateDisplaysSwap(int row1, int row2){
	for (auto &ob : displays) ob->swapRow(row1, row2);
}

void Board::updateDisplaysLevel(int level){
	for (auto &ob : displays) ob->updateLevel(level);
}

void Board::updateDisplaysScore(int score){
	 for (auto &ob : displays) ob->updateScore(score);
}
void Board::updateDisplaysNext(char blockType){
	for (auto &ob : displays) ob->updateNext(blockType);
}

void Board::attach(PlayerDisplay *p){
	displays.emplace_back(p);
	for(auto &b: blocks){
		vector<Cell> cells = b->getCells();
		for(auto &c : cells){
			p->update(c.getContent(), c.getCoord());
		}
	}
	p->updateNext(next->getCells()[0].getContent());
}
bool Board::nextBlock(){
	vector<Block*> newBlocks= level->createPiece(sequence,randomInd, 
							lastPieceCleared);
	lastPieceCleared++;
	for(auto b = newBlocks.begin(); b != --newBlocks.end() ; ++b){
		blocks.emplace_back(*b);
		for(auto &c : (*b)->getCells()){
			if(grid[c.getCoord().y][c.getCoord().x]){
				return false;
			}
		}
		drop();
	}
	
	blocks.emplace_back(next);
	
	next = *--newBlocks.end();
 	updateDisplaysNext(next->getCells()[0].getContent());

	for(auto &c : blocks.back()->getCells()){
		if(grid[c.getCoord().y][c.getCoord().x]){
			return false;
		}
	}
	
	for(auto &c : blocks.back()->getCells()){
		updateDisplays(c.getContent(), c.getCoord());
	}

	return true;
}

Board::~Board(){
	for(auto &b: blocks){
		delete b;
	}
	delete level;
	delete next;

}

void Board::setBlind(bool isBlind){
        blindDisplay = isBlind;
	for(auto &ob : displays) ob->setBlind(isBlind);

}

bool Board::isBlind(){
        return blindDisplay;
}

Block* Board::getActive(){
	return blocks.back();
}

void Board::I(){
	Block * currBlock = blocks.back();
	blocks.pop_back();
	for(auto c : currBlock->getCells()){
		updateDisplays(' ', c.getCoord());
	}
	int currWeight = currBlock->getWeight();
	delete currBlock;
	
	Block * newBlock = new Iblock(currWeight,levelint);
	blocks.push_back(newBlock);
	for(auto c : newBlock->getCells()){
		updateDisplays(c.getContent(), c.getCoord());
	}
} 

void Board::J(){
	Block * currBlock = blocks.back();
	blocks.pop_back();
	for(auto c : currBlock->getCells()){
		updateDisplays(' ', c.getCoord());
	}
	int currWeight = currBlock->getWeight();
	delete currBlock;
	
	Block * newBlock = new Jblock(currWeight,levelint);
	blocks.push_back(newBlock);	
	for(auto c : newBlock->getCells()){
		updateDisplays(c.getContent(), c.getCoord());
	}
}
void Board::L(){
	Block * currBlock = blocks.back();
	blocks.pop_back();
	for(auto c : currBlock->getCells()){
		updateDisplays(' ', c.getCoord());
	}
	int currWeight = currBlock->getWeight();
	delete currBlock;
	
	Block * newBlock = new Lblock(currWeight,levelint);
	blocks.push_back(newBlock);	
	for(auto c : newBlock->getCells()){
		updateDisplays(c.getContent(), c.getCoord());
	}

}
void Board::O(){
	Block * currBlock = blocks.back();
	blocks.pop_back();
	for(auto c : currBlock->getCells()){
		updateDisplays(' ', c.getCoord());
	}

	int currWeight = currBlock->getWeight();
	delete currBlock;
	
	Block * newBlock = new Oblock(currWeight,levelint);
	blocks.push_back(newBlock);	
	for(auto c : newBlock->getCells()){
		updateDisplays(c.getContent(), c.getCoord());
	}


}
void Board::S(){
	Block * currBlock = blocks.back();
	blocks.pop_back();
	for(auto c : currBlock->getCells()){
		updateDisplays(' ', c.getCoord());
	}
	int currWeight = currBlock->getWeight();
	delete currBlock;
	
	Block * newBlock = new Sblock(currWeight,levelint);
	blocks.push_back(newBlock);	
	for(auto c : newBlock->getCells()){
		updateDisplays(c.getContent(), c.getCoord());
	}


}
void Board::Z(){
	Block * currBlock = blocks.back();
	blocks.pop_back();
	for(auto c : currBlock->getCells()){
		updateDisplays(' ', c.getCoord());
	}
	int currWeight = currBlock->getWeight();
	delete currBlock;
	Block * newBlock = new Zblock(currWeight,levelint);
	blocks.push_back(newBlock);	
	for(auto c : newBlock->getCells()){
		updateDisplays(c.getContent(), c.getCoord());
	}



}
void Board::T(){
	Block * currBlock = blocks.back();
	blocks.pop_back();
	for(auto c : currBlock->getCells()){
		updateDisplays(' ', c.getCoord());
	}

	int currWeight = currBlock->getWeight();
	delete currBlock;
	
	Block * newBlock = new Tblock(currWeight,levelint);
	blocks.push_back(newBlock);	
	for(auto c : newBlock->getCells()){
		updateDisplays(c.getContent(), c.getCoord());
	}


}
