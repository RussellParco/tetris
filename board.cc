#include "board.h"

Board::Board(int level = 0, int width, int length): grid{false},
	levelint {level}, width{width}, height{height}, random{false}, 
	lastPieceCleared{0}{

	if(level == 0){
		level = new Level10();
	}else if(level == 1){
		level = new Level1();
	}else if(level == 2){
		level = new Level2();
        }else if (level == 3){
		level = new Level3();
	}else{
		level = new Level4();
	}

}




bool cellsAvailable(std::vector<Cell> exCells, string type, std::vector<vector <bool>> grid){
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

		int cx = 0;
		int cy = 0;
		int  s = 1;
		int c = 0;
	for(int i =0; i <=3 ; i++){
		
		if(type == "clockwise"){
			int xnew = testCells[i].current.x * c - testCells.current.y * s;
			int ynew = testCells[i].current.x * -1 * s + testCells.current.y * c;
			
		}
		else{
			int xnew = testCells[i].current.x * c - testCells[i].current.y * s;
			int ynew = testCells[i].current.x * s + testCells[i].current.y * c;	


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


void counterclockwise(){
	Block recent = blocks.back();
	if (cellsAvailable(recent->cells, "counterclockwise", this->grid)){
		this->block.rotate("counterclockwise");
	}
}

void clockwise(){
	Block recent = blocks.back();
	if (cellsAvailable(recent->cells, "clockwise", this->grid)){
		this->block.rotate("clockwise");
	}
	
}

void right(){
	*Block activeBlock = blocks.back();
	for(auto c : activeBlock->cells){
		if(c.x  == width-1 || grid[c.x+1][c.y]){
			return;
		}
	}
	for(auto c: activeBlock->cells){
		grid[c.x+1][c.y] = 1;
		grid[c.x][c.y] = 0;
	}
	activeBlock->right();
}

void left(){
	*Block activeBlock = blocks.back();
        for(auto c : activeBlock->cells){
                if(c.x == 0 || !grid[c.x-1][c.y]){
                        return;
                }
        }
	for(auto c : activeBlock->cells){
		grid[c.x-1][c.y] = 1;
		grid[c.x][c.y] = 0;
	}
        activeBlock->left();
}

void down(){
	*Block activeBlock = blocks.back();
        for(auto c : activeBlock->cells){
                if(c.y  == height - 1 || !grid[c.x][c.y-1]){
                        return;
                }
	}
	for(auto c : activeBlocks->cells){	      
		grid[c.x][c.y-1] = 1;
		grid[c.x][c.y] = 0;
	}
        
        activeBlock->down();

}
int drop(){
	*Block activeBlock = blocks.back();
        while(drop){
		for(auto c : activeBlock->cells){
        		if(c.x  == width-1 || !grid[c.x][c.y-1]){
				return;
                	}
        	}
		for(auto c : activeBlocks->cells){
			grid[c.x][c.y-1] = 1;
			grid[c.x][c.y] = 0;
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
			rowsCleared ++;
		}
	}

	score += (rowsCleared + levelint) * (rowsCleared + levelint);
	return rowsCleared;
}
void levelup(){
	if(level != 4){
		delete level;
		levelint++;
		if(level == 0){
			level = new Level1();
		}else if(level == 1){
			level = new Level2();
		}else if(level == 2){
			level = new Level3();
                }else{
			level = new Level3();

		}
	}
}

void leveldown(){
	if(level != 0){
                delete level;
                levelint--;
                if(level == 1){
                        level = new Level0();
                }else if(level == 2){
                        level = new Level1();
                }else if(level == 3){
                        level = new Level2();
                }else{
                        level = new Level3();
                }
        }
}

void setRandom(bool set){
	random = set;
}

void setSequence(string file){
	sequence = ifstream(file);
}
void restart(){
	score = 0;
	for(int x = 0; x < width; x++){
		for(int y = 0; y < height; y++){
			grid[x][y] = 0;
		}
	}

	blocks.clear();
}

void dropRows(int row){
	if(row = 0)
		break;
	}
	std::swap(grid[row], grid[row - 1]);
	dropRows(row-1);
}

int clearRow(int row){
	int blockscore;
	for(auto b : blocks){
		for(auto c : b->cells){
			if(b.y == row){
				if( b.remove(c)){
					blockscore += b.getscore();
					blocks.remove(b);
				}
			}

		}
	}
	return blockscore;
}
