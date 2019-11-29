#include "iblock.h"
#include <string>

Iblock::Iblock(char type, int weight, int level):Block('I' , weight, level) {
	for(int i =0; i <= 3; i++){
		
		int xnew= i + 5;
		int ynew= 1;
		char c = 'I';
		Coord newCoord{xnew, ynew};
		Cell newCell{newCoord, c};	
		cells[i]= newCell;
		
	}
}


