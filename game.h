#ifndef GAME
#define GAME
#include <string>
#include <memory>
#include "textCommands.h" 

class Display;
class Board;

class Game{
	std::unique_ptr<Display> textDisplay;
	std::unique_ptr<Display> graphics;
	std::unique_ptr<Board> players[2];
	int turn;
	textCommands Commands;
	int highScore;
	public: 
	Game();
	void play();
	void left();
	void right();
	void down();
	void clockwise();
	void counterclockwise();
	void drop();
        void levelup();
	void leveldown();
	void restart();
	void I();
	void J();
	void L();
	void O();
	void S();
	void Z();
	void T();	
	
};
#endif
