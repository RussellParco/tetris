#include "display.h"

GameDisplay::GameDisplay(int width, int height):height{height},width{width} {};

PlayerDisplay* GameDisplay::addPlayer(int level){
	theDisplay.emplace_back(new PlayerDisplay(width, height, level));
	return theDisplay.back();
}
void GameDisplay::restart(){
	for(auto &it: theDisplay){
		it->restart();
	}
}
GameDisplay::~GameDisplay(){
	for(auto d: theDisplay){
		delete d;
	}
}

