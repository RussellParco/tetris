#include "sblock.h"
#include <string>

Sblock::Sblock(char type, int weight, int level): Block('S', weight, level) {
	for(int i =0; i <= 1; i++){
		int xnew= i + 5;
		int ynew= 0;
		Coord newCoord {xnew, ynew};
		char c= 'S';
		Cell newCell {newCoord, c};
		cells[i] = newCell;	
		
	}
	for(int i =2; i <= 3; i++){
		int xnew= i + 2;
		int ynew= 1;
		Coord newCoord {xnew, ynew};
		char c= 'S';
		Cell newCell {newCoord, c};
		cells[i] = newCell;	
		
	}

}


