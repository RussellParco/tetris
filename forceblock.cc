#include"forceblock.h"

Forceblock::Forceblock(int weight, int level):Block('*',1, 1, weight, level) {
	
	cells.emplace_back({5,3}, '*');
	
}
