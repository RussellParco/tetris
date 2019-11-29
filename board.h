#ifndef BOARD
#define BOARD
#include <vector>
#include <fstream>
#include <string>
#include "block.h"
#include "level.h"
using namespace std;
class Effect;
class Coord;

class Board{
	 vector<vector <bool>> grid;
	 vector<Block*> blocks;
	 Effect *currentEffect;
	 Level *level;
	 int levelint;
	 const int width;
	 const int height;
	 ifstream sequence;
	 int lastPieceCleared;
	 int clearRow(int row);
	 void dropRows(int row);
	 int score;
 	 bool cellsAvailable(std::vector<Cell> exCells, string type, std::vector<vector <bool>> grid);	 
	public:
	 Board(int level, int width, int length);
	 void counterclockwise();
	 void clockwise();
	 void right();
	 void left();
	 void down();
	 int drop();
	 void levelup();
	 void leveldown();
	 void random(string file);
	 void unRandom();
	 void restart();
	 void updateDisplays(char content, Coord c);
	 void updateDisplaysSwap(int row1, int row2);
};
#endif
