#include "game.h"
#include "textdisplay.h"
#include "textCommands.h"
#include "Command.h"
#include "heavyeffect.h"
#include "forceeffect.h"
#include "blindeffect.h"
#include "graphicsdisplay.h"

using namespace std;

Game::Game(bool text, string scriptfile1, string scriptfile2, 
	    int startlevel):turn {0}, highScore{0}
{
	commands = make_unique<textCommands>();

	textDisplay = make_unique<TextDisplay>(11, 18);

	players[0] = make_unique<Board>(startlevel, 11, 18, scriptfile1);
	players[0]->attach(textDisplay->addPlayer(startlevel));
	players[1] = make_unique<Board>(startlevel, 11, 18, scriptfile2);
	players[1]->attach(textDisplay->addPlayer(startlevel));

	textDisplay -> render();	
	if(!text){
		graphics = make_unique<GraphicsDisplay>(11, 18);
		players[0]->attach(graphics->addPlayer(startlevel)); 
		players[1]->attach(graphics->addPlayer(startlevel)); 
	}else{
		graphics = nullptr;
	}
	if(graphics) graphics->render();


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
		delete currCommand;
	}
}

void Game::right(int &prefix){
	for (int i = 0; i < prefix; i++) {
		players[turn]->right();
	}
	if(!(players[turn]->heavy())){
		drop();	
 	} 
	textDisplay->render();
	if(graphics) graphics->render();	
}

void Game::left(int &prefix){
	for (int i = 0; i < prefix; i++) {
		players[turn]->left();
	}
	if(!(players[turn]->heavy())){
		drop();
	}
	textDisplay->render();
	if(graphics) graphics->render();
}

void Game::down(){
	players[turn]->down();
	textDisplay->render();
	if(graphics) graphics->render();
}

void Game::drop(){
	int cleared = players[turn]->drop();
	
	if(!players[turn]->nextBlock()){
		std::cout << "Player " << turn+1 << " Loses!";
		return;
	}

//	Remove Current Effect	
	if(players[turn]->isBlind()){
		players[turn]->setBlind(false);
	} 
	delete currEffect;
	currEffect = new BasicEffect(); 
 
	//Set Effect for next player
	if(cleared >= 2){
		cout << "Choose an Effect for your Opponent" << endl;
		cout << "* heavy" << endl << "* blind" << endl << "* force"<< endl;
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
	textDisplay->render();
	if(graphics) graphics->render();
}

void Game::clockwise(){
	players[turn]->clockwise();
	textDisplay->render();
	if(graphics) graphics->render();
}

void Game::counterclockwise(){
	players[turn]->counterclockwise();
	textDisplay->render();
	if(graphics) graphics->render();
}
void Game::leveldown(){
	players[turn]->leveldown();
	textDisplay->render();
	if(graphics) graphics->render();
}
void Game::levelup(){
	players[turn]->levelup();
	textDisplay->render();
	if(graphics) graphics->render();
}
void Game::restart(){

        textDisplay->restart();
        if(graphics){
              graphics->restart();
        }
        turn = 0; 
	
 	players[0]->restart();
	players[1]->restart();
	textDisplay->render();
	if(graphics) graphics->render();
	 

}

void Game::I(){
	players[turn]->I();
	textDisplay->render();
	if(graphics) graphics->render();
}
void Game::J(){
        players[turn]->J();
	textDisplay->render();
	if(graphics) graphics->render();
}
void Game::L(){
        players[turn]->L();
	textDisplay->render();
	if(graphics) graphics->render();
}
void Game::O(){
        players[turn]->O();
	textDisplay->render();
	if(graphics) graphics->render();
}
void Game::S(){
        players[turn]->S();
	textDisplay->render();
	if(graphics) graphics->render();
}
void Game::Z(){
        players[turn]->Z();
	textDisplay->render();
	if(graphics) graphics->render();
}
void Game::T(){
        players[turn]->T();
	textDisplay->render();
	if(graphics) graphics->render();
}

void Game::random(){
	players[turn]->random();

}
void Game::noRandom(std::string file)
{
	players[turn]->noRandom(file);
}
void Game::sequence(std::string file){
	Command* seq = commands->createSequence(file, new baseCommand());
	seq->execute(*this);
	delete seq;
}

Game::~Game(){
	delete currEffect;
}

