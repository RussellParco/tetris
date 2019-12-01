#include "jblock.h"
#include <string>

Jblock::Jblock(char type,int width, int height, int weight, int level):Block('J',3, 2, weight, level) {
	for(int i =0; i <= 2; i++){
		
		int xnew = i + 5;
		int ynew = 3;	
		Coord newCoord {xnew, ynew}; 
		char c = 'J';
		cells.emplace_back(newCoord, c);
	}
	int x4= 5;
	int y4 = 2;
	Coord anotherCoord {x4, y4};
	char j = 'J';
	cells.emplace_back(anotherCoord, j);
	
}

