#include "board.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
using namespace std;

Board::Board(int level, int width, int height):
	levelint {level}, width{width}, height{height},	lastPieceCleared{0},
	randomInd{false}
{

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

}

bool Board::cellsAvailable(std::vector<Cell> exCells, string type, std::vector<vector <bool>> grid){
	vector<Cell> testCells(4);
	for(int i =0; i <= 3; i++){
		testCells[i].setCoord({exCells[i].getCoord().x, exCells[i].getCoord().y}); 
		
	}
	int top = testCells[0].getCoord().y;
	int left = testCells[0].getCoord().x;

		for(int i=0; i <= 3; i++){
	
		if(testCells[i].getCoord().y >= top){
				top = testCells[i].getCoord().y;
			}
		}
		for(int i=0; i <= 3; i++){
			if(testCells[i].getCoord().x <= left){
				left = testCells[i].getCoord().x;
			}
		}

	for(int i =0; i <=3 ; i++){
		int xnew;
                int ynew; 		
		if(type == "clockwise"){
			xnew = -1*testCells[i].getCoord().y;
			ynew = testCells[i].getCoord().x * -1;
			
		}
		else{
			xnew = -1 * testCells[i].getCoord().y;
			ynew = testCells[i].getCoord().x;	


		}
		testCells[i].setCoord({xnew + left, ynew + top});
	}

	
 	int x = 0;
	int y = 0;

	for(int i = 0; i <= 3; i++ ){
		x = testCells[i].getCoord().x;
		y = testCells[i].getCoord().y;	
		if(grid[x][y] == 1){
			return false;
		}
	}

	return true;
	
}


void Board::counterclockwise(){
	Block *recent = blocks.back();
	if (cellsAvailable(recent->getCells(), "counterclockwise", this->grid)){
		recent->rotate("counterclockwise");
	}

}

void Board::clockwise(){
	Block *recent = blocks.back();
	if (cellsAvailable(recent->getCells(), "clockwise", this->grid)){
		recent->rotate("clockwise");
	}
}

void Board::right(){
	Block* activeBlock = blocks.back();
	for(auto c : activeBlock->getCells()){
		if(c.getCoord().x  == width-1 || grid[c.getCoord().x+1][c.getCoord().y]){
			return;
		}
	}
	for(auto c: activeBlock->getCells()){
		grid[c.getCoord().x+1][c.getCoord().y] = 1;
		grid[c.getCoord().x][c.getCoord().y] = 0;
		updateDisplays(' ', c.getCoord());
                updateDisplays(c.getContent(), c.getCoord());

	}
	activeBlock->right();
}

void Board::left(){
	Block* activeBlock = blocks.back();
        for(auto c : activeBlock->getCells()){
                if(c.getCoord().x == 0 || !grid[c.getCoord().x-1][c.getCoord().y]){
                        return;
                }
        }
	for(auto c : activeBlock->getCells()){
		grid[c.getCoord().x-1][c.getCoord().y] = 1;
		grid[c.getCoord().x][c.getCoord().y] = 0;
		updateDisplays(' ', c.getCoord());
                updateDisplays(c.getContent(), c.getCoord());

	}
        activeBlock->left();
}

void Board::down(){
	Block *activeBlock = blocks.back(); 
        for(auto c : activeBlock->getCells()){
                if(c.getCoord().y  == height - 1 || !grid[c.getCoord().x][c.getCoord().y-1]){
                        return;
                }
	}
	for(auto c : activeBlock->getCells()){	      
		grid[c.getCoord().x][c.getCoord().y-1] = 1;
		grid[c.getCoord().x][c.getCoord().y] = 0;
		updateDisplays(' ', c.getCoord());
                updateDisplays(c.getContent(), {c.getCoord().x, c.getCoord().y-1});

	}
        
        activeBlock->down();

}
int Board::drop(){
	bool dropInd = true;
	Block* activeBlock = blocks.back();
        while(dropInd){
		for(auto c : activeBlock->getCells()){
        		if(c.getCoord().x  == width-1 || !grid[c.getCoord().x][c.getCoord().y-1]){
				dropInd = false;
				break;
                	}
        	}
		for(auto c : activeBlock->getCells()){
			grid[c.getCoord().x][c.getCoord().y-1] = 1;
			grid[c.getCoord().x][c.getCoord().y] = 0;
			updateDisplays(' ', c.getCoord());
			updateDisplays(c.getContent(), {c.getCoord().x, c.getCoord().y-1});
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
			score += this->clearRow(y);
			dropRows(y);
			rowsCleared++;
		}
	}

	score += (rowsCleared + levelint) * (rowsCleared + levelint);
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


