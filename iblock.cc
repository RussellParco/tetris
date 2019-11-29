#include "iblock.h"
#include <string>

Iblock::Iblock(char type, int weight): type{'I'}, weight{weight} {
	for(int i =0; i <= 3; i++){
		this->cells[i].current.x= i + 5;
		this->cells[i].current.y= 1;
		this->cells[i].content = 'I';	
	}
}


