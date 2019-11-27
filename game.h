#ifndef GAME
#define GAME
#include <string>
class Game{
	Display * textDisplay;
	Display * graphics;
	players vector<Board>;
	ifstream * sequence;
	Player * turn;
	textCommands Commands;
	int highScore;
	public: 
	Game();
	~Game();
	ExecuteCommnand(string command, Board board);
};
#endif
