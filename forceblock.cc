#include"forceblock.h"

Forceblock::Forceblock(int weight, int level):Block('*',1, 1, weight, level) {
	Coord c = {5,3};	
	cells.emplace_back(c, '*');
	
}
