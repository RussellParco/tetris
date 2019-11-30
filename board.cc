#include "board.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
using namespace std;

Board::Board(int level, int width, int height, string seq):
	levelint {level}, width{width}, height{height}, 
	sequence{ifstream(seq)}, lastPieceCleared{0}, randomInd{false}
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
	blocks.emplace_back(this->level->createPiece(sequence, 
				randomInd, lastPieceCleared));

	vector<Cell> newCells = blocks.back()->getCells();
	
}

bool Board::cellsAvailable(std::vector<Cell> exCells, string type, std::vector<vector <bool>> grid){
	vector<Cell> testCells(4);
	for(int i =0; i <= 3; i++){
		testCells[i].setCoord({exCells[i].getCoord().x, exCells[i].getCoord().y}); 
		
	}
	int bottom = testCells[0].getCoord().y;
	int left = testCells[0].getCoord().x;

		for(int i=0; i <= 3; i++){
	
			if(testCells[i].getCoord().y <= bottom){
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
		
			xnew =  ynew;
			ynew = -1 * temp;
			ynew += (width - 1);
		}
		else{
			int temp = xnew;
			xnew = -1 * ynew;
			ynew = temp;
			xnew += (height -1);	


		}
		
		testCells[i].setCoord({xnew + left, ynew + bottom});
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
//	if (cellsAvailable(recent->getCells(), "counterclockwise", this->grid)){
		for(auto c : recent->getCells()){
			updateDisplays(' ', c.getCoord());
		}
		recent->rotate("counterclockwise");	
		for(auto c : recent->getCells()){
                        updateDisplays(c.getContent(), c.getCoord());
                }

//	}

}

void Board::clockwise(){
	Block *recent = blocks.back();
//	if (cellsAvailable(recent->getCells(), "clockwise", this->grid)){
		for(auto c : recent->getCells()){
                        updateDisplays(' ', c.getCoord());
                }
                recent->rotate("clockwise");
                for(auto c : recent->getCells()){
                        updateDisplays(c.getContent(), c.getCoord());
                }

	//}
}

void Board::right(){
	
	Block* activeBlock = blocks.back();
	for(auto c : activeBlock->getCells()){
		if(c.getCoord().x  == width-1 || grid[c.getCoord().y][c.getCoord().x + 1]){
			return;
		}
	}
	for(auto c: activeBlock->getCells()){
		updateDisplays(' ', c.getCoord());
	}
	activeBlock->right();
        for(auto c : activeBlock->getCells()){
                updateDisplays(c.getContent(), c.getCoord());
        }

}

void Board::left(){
	Block* activeBlock = blocks.back();
        for(auto c : activeBlock->getCells()){
                if(c.getCoord().x == 0 || grid[c.getCoord().y][c.getCoord().x-1]){
                        
			return;
                
		}
	}
	for(auto c : activeBlock->getCells()){
		updateDisplays(' ', c.getCoord());
	}
	activeBlock->left();
	for(auto c : activeBlock->getCells()){
		updateDisplays(c.getContent(), c.getCoord());
        }
}

void Board::down(){
	Block *activeBlock = blocks.back(); 
        for(auto c : activeBlock->getCells()){
                if(c.getCoord().y  == height - 1 || grid[c.getCoord().y+1][c.getCoord().x]){
                        return;
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
int Board::drop(){
	bool dropInd = true;
	Block* activeBlock = blocks.back();
        for(auto c : activeBlock->getCells()){
                updateDisplays(' ', c.getCoord());
        }

	while(dropInd){
		for(auto c : activeBlock->getCells()){
        		if((c.getCoord().y  == height-1) || 
					grid[c.getCoord().y+1][c.getCoord().x]){
				dropInd = false;
				break;
                	}
        	}
		if(dropInd){
        		activeBlock->down();
		}
	}

	for(auto c : activeBlock->getCells()){
                grid[c.getCoord().y][c.getCoord().x] = 1;
		updateDisplays(c.getContent(), c.getCoord());
        }	

	int rowsCleared = 0;
	for(int y = 0; y < height; y++){
		bool clearRow = true;
		for(int x = 0; x < width; x++){
			if(!grid[x][y]){
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

	score += (rowsCleared + levelint) * (rowsCleared + levelint);
	blocks.emplace_back(level->createPiece(sequence,
                                randomInd, lastPieceCleared));
	for(auto c : blocks.back()->getCells()){
        	updateDisplays(c.getContent(), c.getCoord());
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
                }else{
			level = new Level4();

		}
		levelint++;
	}
}

void Board::leveldown(){
	if(levelint != 0){
                delete level;
                if(levelint == 1){
                        level = new Level0() ;
                }else if(levelint == 2){
                        level = new Level1();
                }else if(levelint == 3){
                        level = new Level2();
                }else{
                        level = new Level3();
                }
		levelint--;
        }
}

void Board::random(){
	//TODO
}

void Board::unRandom(string file){
	//TODO
}

void Board::restart(){
	score = 0;
	for(int x = 0; x < width; x++){
		for(int y = 0; y < height; y++){
			grid[x][y] = 0;
		}
	}

	blocks.clear();
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
	for(auto b = blocks.begin(); b != blocks.end();  ++b ){
		vector<Cell> cells = (*b)->getCells();
		for(auto c = cells.begin(); c != cells.end();  ++c ){
			if((*c).getCoord().y == row){
				if( (*b)->remove((int)distance(cells.begin(),c))){
					blockscore += (*b)->getScore();
					blocks.erase(blocks.begin()+distance(blocks.begin(),b));
				}
				grid[(*c).getCoord().x][(*c).getCoord().y] = 0;
				updateDisplays(' ', (*c).getCoord());
				
			}

		}
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
void Board::attach(PlayerDisplay *p){
	displays.emplace_back(p);
	for(auto b: blocks){
		vector<Cell> cells = b->getCells();
		for(auto c : cells){
			p->update(c.getContent(), c.getCoord());
		}
	}
}

