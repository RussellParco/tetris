#include "board.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"

Board::Board(int level = 0, int width, int length):
	levelint {level}, width{width}, height{height}, random{false}, 
	lastPieceCleared{0}{

	if(levelint == 0){
		level = new Level0();
	}else if(levelint == 1){
		level = new Level1();
	}else if(levelint == 2){
		level = new Level2();
        }else if (levelint == 3){
		level = new Level3();
	}else{
		level = new Level4();
	}

}

bool Board::cellsAvailable(std::vector<Cell> exCells, string type, std::vector<vector <bool>> grid){
	std::vector<Cell> testCells(4);
	for(int i =0; i <= 3; i++){
		testCells[i].current.x = exCells[i].current.x;
		testCells[i].current.y = exCells[i].current.y; 
		
	}
	int top = testCells[0].current.y;
	int left = testCells[0].current.x;

		for(int i=0; i <= 3; i++){
			if(testCells[i].current.y >= top){
				top = testCells[i].current.y;
			}
		}
		for(int i=0; i <= 3; i++){
			if(testCells[i].current.x <= left){
				left = testCells[i].current.x;
			}
		}

	for(int i =0; i <=3 ; i++){
		int xnew;
                int ynew; 		
		if(type == "clockwise"){
			xnew = -1*testCells.current.y;
			ynew = testCells[i].current.x * -1;
			
		}
		else{
			xnew = -1 * testCells[i].current.y;
			ynew = testCells[i].current.x * s;	


		}
		testCells[i].current.x = xnew + left;
		testCells[i].current.y = ynew + top;
	}

	
 	int x = 0;
	int y = 0;

	for(int i = 0; i <= 3; i++ ){
		x = testCells[i].current.x;
		y = testCells[i].current.y;	
		if(grid[x][y] == 1){
			return false;
		}
	}

	return true;
	
}


void Board::counterclockwise(){
	Block recent = blocks.back();
	if (cellsAvailable(recent->getcells(), "counterclockwise", this->grid)){
		this->block.rotate("counterclockwise");
	}

}

void Board::clockwise(){
	Block recent = blocks.back();
	if (cellsAvailable(recent->getcells(), "clockwise", this->grid)){
		this->block.rotate("clockwise");
	}
	
}

void Board::right(){
	Block* activeBlock = blocks.back();
	for(auto c : activeBlock->getcells()){
		if(c.x  == width-1 || grid[c.x+1][c.y]){
			return;
		}
	}
	for(auto c: activeBlock->getcells()){
		grid[c.x+1][c.y] = 1;
		grid[c.x][c.y] = 0;
		notifyObservers(' ', c.x, c.y);
                notifyObservers(activeBlock.content(), c.x+1, c.y);

	}
	activeBlock->right();
}

void Board::left(){
	Block* activeBlock = blocks.back();
        for(auto c : activeBlock->getcells()){
                if(c.x == 0 || !grid[c.x-1][c.y]){
                        return;
                }
        }
	for(auto c : activeBlock->getcells()){
		grid[c.x-1][c.y] = 1;
		grid[c.x][c.y] = 0;
		updateDisplays(' ', c.x, c.y);
                updateDsiplays(activeBlock->content(), c.x-1, c.y);

	}
        activeBlock->left();
}

void Board::down(){
	Block *activeBlock = blocks.back(); 
        for(auto c : activeBlock->getcells()){
                if(c.y  == height - 1 || !grid[c.x][c.y-1]){
                        return;
                }
	}
	for(auto c : blocks->getcells()){	      
		grid[c.x][c.y-1] = 1;
		grid[c.x][c.y] = 0;
		updateDisplays(' ', c.x, c.y);
                updateDisplays(activeBlock->content(), c.x, c.y-1);

	}
        
        activeBlock->down();

}
int Board::drop(){
	Block* activeBlock = blocks.back();
        while(drop){
		for(auto c : activeBlock->getcells()){
        		if(c.x  == width-1 || !grid[c.x][c.y-1]){
				return;
                	}
        	}
		for(auto c : blocks->getcells()){
			grid[c.x][c.y-1] = 1;
			grid[c.x][c.y] = 0;
			updateDisplays(' ', c.x, c.y, this);
			updateDisplays(activeBlock.content(), c.x, c.y-1);
		}

        	activeBlock->down();
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
			score += clearRow(y);
			dropRows(y);
			rowsCleared++;
		}
	}

	score += (rowsCleared + levelint) * (rowsCleared + levelint);
	return rowsCleared;
}
void Board::levelup(){
	if(level != 4){
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
	if(level != 0){
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

void Board::random(string file){
	//TODO
}

void Board::unRandom(){
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
	int blockscore;
	for(auto b : blocks){
		vector<Cell> cells = b->getcellS();
		for(auto c : cells){
			if(c.y == row){
				if( b.remove(cells.begin() - c)){
					blockscore += b.getScore();
					blocks.erase(blocks.begin()- b);
				}
				grid[c.x][c.y] = 0;
				updateDisplays(' ', c->getCoord());
				
			}

		}
	}
	return blockscore;
}
