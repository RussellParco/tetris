#ifndef GAME
class Game{
	*Display textDisplay;
	*Display graphics;
	players vector<Board>;
	*ifstream sequence;
	*Player turn;
	textCommands Commands;
	int highScore;
	public:
	ExecuteCommnad(string, Board);
};
#define GAME
#endif
