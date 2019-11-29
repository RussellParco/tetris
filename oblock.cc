#include "oblock.h"
#include <string>

Oblock::Oblock(char type, int weight): type{O}, weight{weight} {
	for(int i =0; i <= 1; i++){
		this->cells[i].current.x= i + 5;
		this->cells[i].current.y= 0;	
	}
	this->cells[2].current.x= 5;
	this->cells[2].current.y = 1;
	this->cells[3].current.x= 6
	this->cells[3].current.y= 1;
 
	for(int i =0; i <=3; i++){
		this->cells[i].content = 'O';
	}
}


