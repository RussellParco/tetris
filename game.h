#ifndef GAME
#define GAME
#include <string>
class Game{
	unique_ptr<Display> textDisplay;
	unique_ptr<Display> graphics;
	unique_ptr<Board> players[2];
	Player  *turn;
	textCommands Commands;
	int highScore;
	public: 
	Game();
	void play();
};
#endif
