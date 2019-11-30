#include "lblock.h"
#include <string>

Lblock::Lblock(char type,int width, int height, int weight, int level): Block('L',3,2, weight, level) {
	for(int i =0; i <= 2; i++){
		int xnew= i + 5;
		int ynew= 1;
		Coord newCoord{xnew, ynew};
		char c = 'L';
		cells.emplace_back(newCoord, c);
	
	}
	int x4= 7;
	int y4 = 0;
	Coord anotherCoord {x4, y4};
	char l = 'L';
	cells.emplace_back(anotherCoord, l);
	
}

