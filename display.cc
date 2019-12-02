#include "display.h"

Display::Display(int width, int height):height{height},width{width} {};

PlayerDisplay* Display::addPlayer(int level){
	theDisplay.emplace_back(new PlayerDisplay(width, height, level));
	return theDisplay.back();
}
void Display::restart(){
	for(auto &it: theDisplay){
		it->restart();
	}
}
Display::~Display(){
	for(auto d: theDisplay){
		delete d;
	}
}

