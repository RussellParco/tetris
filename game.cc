#include "game.h"
#include <memory>
using namespace std;

Game::Game(bool text, int seed, string scriptfile1, string scriptfile2, 
	    int startlevel): commands{textCommands}
{
	textDisplay = unique_ptr<TextDisplay>();
	if(!text){
		graphics = unique_ptr<GraphicsDisplay>();
	}else{
		graphics = nullptr;
	}

	players[0] = unique_ptr<Board>();
	players[1] = unique_ptr<Board>();
	turn = players[0];
	highScore = 0;
}

void Game::play(){
	string strCommand;
	Commnad *currCommand;
	while(cin >> strCommand){
		currComand = commands.getCommand(strCommand);
		currCommand->executeCommad();
	}
}


