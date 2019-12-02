#include "game.h"
#include "textdisplay.h"
#include "textCommands.h"
#include "Command.h"
#include "heavyeffect.h"
#include "forceeffect.h"
#include "blindeffect.h"


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
	if(!(players[turn]->heavy())){
		drop();	
 	}
	
}
void Game::left(){
	players[turn]->left();
	if(!(players[turn]->heavy())){
		drop();	
 	}

}

void Game::down(){
	players[turn]->down();
}
void Game::drop(){
	//Remove Current Effect	
			
	if(players[turn]->isBlind()){
		players[turn]->setBlind(false);
	} 
	delete currEffect;
	currEffect = new BasicEffect();
 
	//Set Effect for next player
	if(players[turn]->drop() >= 2){
		cout << "Choose an Effect for your Opponent" << endl;
		cout << "* heavy" << endl << "* blind" << endl << "* force";
		string newEffect;
		cin >> newEffect;	

		if(newEffect == "blind"){
 	               currEffect = new BlindEffect(currEffect);
        	}
        	else if (newEffect == "heavy"){
                	currEffect = new HeavyEffect(currEffect);
        	}
        	else if(newEffect == "force"){
                	currEffect = new ForceEffect(currEffect);
        	} 
	}
			
	//set score
	if(players[turn]->getScore() > highScore){
		highScore = players[turn]->getScore();
	}
	
	//change turn
	turn++;
	if(turn == 2){
		turn = 0;
	}
	currEffect->applyEffect(*players[turn]);
 
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
