#ifndef BOARD
#define BOARD
#include <vector>
#include <fstream>
#include <string>
#include "block.h"
using namespace std;
class Effect;
class Level;

class Board{
	 vector<vector <bool>> grid;
	 vector<Block> blocks;
	 Effect *currentEffect;
	 Level *level;
	 int levelint;
	 const int width;
	 const int height;
	 ifstream sequence;
	 bool random;
	 int lastPieceCleared;
	 int clearRow(int row);
	 void dropRows(int row);
	 int score;
 	 bool cellsAvailable(std::vector<Cell> exCells, string type, std::vector<vector <bool>> grid);	 
	public:
	 void counterclockwise();
	 void clockwise();
	 void right();
	 void left();
	 void down();
	 int drop();
	 void levelup();
	 void leveldown();
	 void setRandom(bool set);
	 void setSequence(string file);
	 void restart();
	 void updateDisplays(char content, int row, int col);
	 void updateDisplaysSwap(int row1, int row2);
};
#endif
