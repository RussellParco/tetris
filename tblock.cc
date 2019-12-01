#include "tblock.h"
#include <string>

Tblock::Tblock(char type, int weight, int level):Block('T', 3,2, weight, level) {
	for(int i =0; i <= 2; i++){
		int xnew= i + 4;
		int ynew= 2;
		Coord newCoord {xnew, ynew};
		char c ='T';
		cells.emplace_back(newCoord, c);
			
	}
	int x4= 5;
	int y4 = 3;
	Coord anotherCoord {x4, y4};
	char d = 'T';
	cells.emplace_back(anotherCoord, d);
	

}


