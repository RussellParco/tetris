#include "zblock.h"
#include <string>

Zblock::Zblock(char type,int width,int height, int weight, int level): Block('Z',3,2, weight, level) {
	for(int i =0; i <= 1; i++){
		int xnew= i + 4;
		int ynew= 2;
		Coord newCoord {xnew, ynew};
		char c= 'Z';
		cells.emplace_back(newCoord, c);
		
	}
	for(int i =2; i <= 3; i++){
		int xnew= i + 3;
		int ynew= 3;
		Coord newCoord {xnew, ynew};
		char c= 'Z';
		cells.emplace_back(newCoord, c);
		
	}
}


