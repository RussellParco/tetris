#ifndef BOARD
#define BOARD
class Board{
	 vector<vector <bool>> grid;
	 bool **blocks;
	 *Effect currentEffect;
	 *Level level;
	 int levelint;
	 const int width;
	 const int height;
	 ifstream sequencec;
	 bool random;
	 int lastPieceCleared;
	 int clearRow(int row);
	 void dropRows(int row);
	
	public:
	 void counterclockwise();
	 void clockwise();
	 void right();
	 void left();
	 void down();
	 void drop();
	 void levelup();
	 void leveldown();
	 void setRandom(bool set);
	 void setSequence(string file);
	 void restart();
};
#endif
