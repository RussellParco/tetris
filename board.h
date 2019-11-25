#ifndef BOARD
#define BOARD
class Board{
	 vector<vector <Cell>> theBoard;
	 vector<Block> blocks;
	 *Effect currentEffect;
	 *Level level;
	 int levelint;
	 const int width;
	 const int height;
	 *ifstream sequencec;
	 bool random;
	 int lastPieceCleared;
	
	public:
	 void rotate(const int direction);
	 void right();
	 void left();
	 void down();
	 void drop();
	 void levelup();
	 void leveldown();
	 void swapRand();
	 void setSquence();
	 void restart();
};
#endif
