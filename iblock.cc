#include "iblock.h"
#include <string>
using namespace std;

Iblock::Iblock(char type, int weight, int level):Block('I', 4, 1,  weight, level) {
	for(int i =0; i <= 3; i++){
		
		int xnew= i + 5;
		int ynew= 3;
		char c = 'I';
		Coord newCoord{xnew, ynew};
		cells.emplace_back(newCoord, c);		
		
	}
}


