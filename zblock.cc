#include "zblock.h"
#include <string>

Zblock::Zblock(char type, int weight, int level): Block('Z', weight, level) {
	for(int i =0; i <= 1; i++){
		int xnew= i + 4;
		int ynew= 0;
		Coord newCoord {xnew, ynew};
		char c= 'Z';
		cells.emplace_back(newCoord, c);
		
	}
	for(int i =2; i <= 3; i++){
		int xnew= i + 3;
		int ynew= 1;
		Coord newCoord {xnew, ynew};
		char c= 'Z';
		cells.emplace_back(newCoord, c);
		
	}
}


