#ifndef BOARD
#define BOARD
#include <vector>
#include <fstream>
#include <string>
#include "block.h"
#include "level.h"
#include "playerdisplay.h"

using namespace std;
class Effect;
struct Coord;

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
	 bool randomInd;
	 vector<PlayerDisplay*> displays;
 	 bool cellsAvailable(std::vector<Cell> exCells, string type,
			 std::vector<vector <bool>> grid, int blockWidth, int blockHeight);	
	 void updateDisplays(char content, Coord c);
	 void updateDisplaysSwap(int row1, int row2);
	 void updateDisplaysScore(int score);
	 void updateDisplaysLevel(int level);
	public:
	 Board(int level, int width, int height, string seq);
	 void counterclockwise();
	 void clockwise();
	 void right();
	 void left();
	 void down();
	 int drop();
	 void levelup();
	 void leveldown();
	 void random();
	 void unRandom(string file);
	 void restart();
	 void attach(PlayerDisplay *p);
	 int getScore();
	 bool nextBlock();

};
#endif
