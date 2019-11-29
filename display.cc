#include "display.h"

Display::Display(int width, int height):height{height},width{width} {};

PlayerDisplay* Display::addPlayer(int level){
	theDisplay.emplace_back(width, height, level);
	return theDisplay.back();
}
