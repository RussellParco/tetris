	#include "game.h"
#include "textdisplay.h"
#include "textCommands.h"
#include "Command.h"
using namespace std;

Game::Game(bool text, int seed, string scriptfile1, string scriptfile2, 
	    int startlevel):turn {0}, highScore{0}
{
	commands = new textCommands();

	textDisplay = make_unique<TextDisplay>(11, 18);
	if(!text){
		//graphics = unique_ptr<GraphicsDisplay>();
	}else{
		//graphics = nullptr;
	}

	players[0] = make_unique<Board>(startlevel, 11, 18, scriptfile1);
	players[0]->attach(textDisplay->addPlayer(startlevel));
	players[1] = make_unique<Board>(startlevel, 11, 18, scriptfile2);
	players[1]->attach(textDisplay->addPlayer(startlevel));
	textDisplay -> render();
}

void Game::play(){
	string strCommand;
	Command *currCommand;
	while(cin >> strCommand){

		currCommand = commands->getCommand(strCommand);
		if(currCommand == nullptr){
		continue;
		}
		currCommand->execute(*this);
		textDisplay->render();
	}
}

void Game::right(){
	players[turn]->right();
}
void Game::left(){
	players[turn]->left();
}
void Game::down(){
	players[turn]->down();
}
void Game::drop(){
	if(players[turn]->drop() >= 2){
		cout << "Choose an Effect for your Opponent" << endl;
		cout << "* Heavy" << endl << "* Blind" << endl << "* Force";
	/*	string newEffect;
		cin >> newEffect;	
		cin << players[turn + 1]->addEffect(newEffect);
	*/}
	if(players[turn]->getScore() > highScore){
		highScore = players[turn]->getScore();
	}
	turn++;
	if(turn == 2){
		turn = 0;
	}

}
void Game::clockwise(){
	players[turn]->clockwise();
}

void Game::counterclockwise(){
	players[turn]->counterclockwise();
}
void Game::leveldown(){
	players[turn]->leveldown();
}
void Game::levelup(){
	players[turn]->levelup();
}
void Game::restart(){
	players[0]->clockwise();
	players[1]->restart();
	textDisplay = unique_ptr<TextDisplay>();
	//if(graphics){
	//	graphics = unique_ptr<GraphicsDisplay>();
	//}
	turn = 0;
}
void Game::I(){
	//players[turn]->I();
}
void Game::J(){
        //players[turn]->J();
}
void Game::L(){
        //players[turn]->L();
}
void Game::O(){
        //players[turn]->O();
}
void Game::S(){
        //players[turn]->S();
}
void Game::Z(){
        //players[turn]->Z();
}
void Game::T(){
        //players[turn]->T();
}

void Game::random(){
//TODO
}
void Game::noRandom(std::string file)
{
//TODO
}
void Game::sequence(std::string file){
//TODO
}
