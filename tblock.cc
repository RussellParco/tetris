#include "tblock.h"
#include <string>

Tblock::Tblock(char type, int weight, int level):Block('T', weight, level) {
	for(int i =0; i <= 2; i++){
		int xnew= i + 4;
		int ynew= 0;
		Coord newCoord {xnew, ynew};
		char c ='T';
		Cell newCell {newCoord, c};
		cells[i] = newCell;	
	}
	int x4= 4;
	int y4 = 1;
	Coord anotherCoord {x4, y4};
	char d = 'T';
	Cell anotherCell {anotherCoord, d};
	cells[3]= anotherCell;

}


