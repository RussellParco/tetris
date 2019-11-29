#include "lblock.h"
#include <string>

Lblock::Lblock(char type, int weight, int level): Block('L', weight, level) {
	for(int i =0; i <= 2; i++){
		int xnew= i + 5;
		int ynew= 1;
		Coord newCoord{xnew, ynew};
		char c = 'L';
		Cell newCell {newCoord, c};
		cells[i] = newCell;	
	}
	int x4= 7;
	int y4 = 0;
	Coord anotherCoord {x4, y4};
	char l = 'L';
	Cell anotherCell {anotherCoord, l};
	cells[3]= anotherCell ;
}

