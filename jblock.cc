#include "jblock.h"
#include <string>

Jblock::Jblock(char type, int weight, int level):Block('J', weight, level) {
	for(int i =0; i <= 2; i++){
		
		int xnew = i + 5;
		int ynew = 1;	
		Coord newCoord {xnew, ynew}; 
		char c = 'J';
		Cell newCell {newCoord, c};
		cells[i] = newCell;
	}
	int x4= 5;
	int y4 = 0;
	Coord anotherCoord {x4, y4};
	char j = 'J';
	Cell anotherCell{anotherCoord, j};
	cells[3] = anotherCell;

}

