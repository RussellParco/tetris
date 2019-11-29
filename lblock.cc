#include "lblock.h"
#include <string>

Lblock::Lblock(char type, int weight): type{L}, weight{weight} {
	for(int i =0; i <= 2; i++){
		this->cells[i].current.x= i + 5;
		this->cells[i].current.y= 1;	
	}
	this->cells[3].current.x= 7;
	this->cells[3].current.y = 0;

	for(int i =0; i <=3; i++){
		this->cells[i].content = 'L';
	}
}

