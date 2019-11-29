#include "iblock.h"
#include <string>
using namespace std;

Iblock::Iblock(char type, int weight, int level):Block('I' , weight, level) {
	for(int i =0; i <= 3; i++){
		
		int xnew= i + 5;
		int ynew= 1;
		char c = 'I';
		Coord newCoord{xnew, ynew};
		cells.emplace_back(newCoord, c);		
		
	}
}


