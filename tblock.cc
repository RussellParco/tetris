#include "tblock.h"
#include <string>

Tblock::Tblock(char type, int weight): type{T}, weight{weight} {
	for(int i =0; i <= 2; i++){
		this->cells[i].current.x= i + 4;
		this->cells[i].current.y= 0;	
	}
	this->cells[3].current.x= 4;
	this->cells[3],.current.y = 1;

	for(int i =0; i <=3; i++){
		this->cells[i].content = 'T';
	}
}


