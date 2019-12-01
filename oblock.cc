#include "oblock.h"
#include <string>

Oblock::Oblock(char type,int width, int height , int weight, int level): Block('O',2,2, weight, level) {
	for(int i =0; i <= 1; i++){
		int xnew= i + 5;
		int ynew= 2;
		Coord newCoord {xnew, ynew};
		char c = 'O';
		cells.emplace_back(newCoord, c);
		
	}
	for(int i =2; i <= 3; i++){
		int xnew= i + 3;
		int ynew= 3;
		Coord newCoord {xnew, ynew};
		char c = 'O';
		cells.emplace_back(newCoord, c);
		
	}


}


