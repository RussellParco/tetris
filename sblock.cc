#include "sblock.h"
#include <string>

Sblock::Sblock(char type, int weight, int level): Block('S',3,2, weight, level) {
	for(int i =0; i <= 1; i++){
		int xnew= i + 5;
		int ynew= 2;
		Coord newCoord {xnew, ynew};
		char c= 'S';
		cells.emplace_back(newCoord, c);
		
		
	}
	for(int i =2; i <= 3; i++){
		int xnew= i + 2;
		int ynew= 3;
		Coord newCoord {xnew, ynew};
		char c= 'S';
		cells.emplace_back(newCoord, c);
		
		
	}

}


