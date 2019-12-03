#ifndef PLAYERDISPLAY
#define PLAYERDISPLAY
#include <vector>
#include <utility>
#include "coord.h"
#include <iostream>
class PlayerDisplay{
	int width;
	int height;	
	int level;
	int score;
	bool blind;
	char next;
	std::vector<char> theDisplay;
	public:
	PlayerDisplay(int width, int height, int level);
	void updateScore(int score);
	void updateLevel(int level);
	void update(char content, Coord c);
	char getCell(int row,int col)const;
	int getLevel()const;
	int getScore()const;
	void swapRow(int row1, int row2);
       	void restart();
	~PlayerDisplay();
	void setBlind(bool flag);
	void updateNext(char blockType);
	char getNext();
};
#endif

