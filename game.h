#ifndef GAME
#define GAME
#include <string>
#include <memory>
#include "board.h"
#include "display.h"

class textCommands;

class Game{
	std::unique_ptr<Display> textDisplay;
	std::unique_ptr<Board> players[2];
	int turn;
	std::unique_ptr<textCommands> commands;
	int highScore;
	public: 
	Game(bool text, string scriptfile1, 
		std::string scriptfile2, int startlevel);
	~Game();
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
	void random();
	void noRandom(std::string file);	
	void sequence(std::string file);	
};
#endif
