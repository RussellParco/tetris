#ifndef BOARD
#define BOARD
#include <vector>
#include <fstream>
#include <string>
#include "level.h"
#include "playerdisplay.h"

using namespace std;
class Effect;
struct Coord;

class Board{
	 vector<vector <bool>> grid;
	 vector<Block*> blocks;
	 Level *level;
	 int levelint;
	 const int width;
	 const int height;
	 ifstream sequence;
	 int lastPieceCleared;
	 int clearRow(int row);
	 void dropRows(int row);
	 int score;
	 bool blindDisplay; 	
	 vector<PlayerDisplay*> displays;
	 bool randomInd;
	 string randSeq;
	 string defaultSeq;
 	 bool cellsAvailable(std::vector<Cell> exCells, string type,
			 std::vector<vector <bool>> grid, int blockWidth, int blockHeight);	
	 void updateDisplaysSwap(int row1, int row2);
	 void updateDisplaysScore(int score);
	 void updateDisplaysLevel(int level);
	public:
	 bool isBlind();
	 void setBlind(bool isBlind);
	 void updateDisplays(char content, Coord c);
	 Board(int level, int width, int height, string seq);
	 ~Board();
	 void counterclockwise();
	 void clockwise();
	 void right();
	 void left();
	 void down();
	 int drop();
	 void levelup();
	 void leveldown();
	 void random();
	 void noRandom(string file);
	 void restart();
	 void attach(PlayerDisplay *p);
	 int getScore();
	 bool nextBlock();
	 bool heavy();
	 void I();
	 void J();
	 void L();
	 void O();
	 void S();
	 void Z();
	 void T();
	 Block* getActive();
};
#endif
