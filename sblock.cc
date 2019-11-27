#include "sblock.h"
#include <string>

Sblock::Sblock(char type, int weight): type{type}, weight{weight} {

	for(int i =0; i <= 1; i++){
		this->cells[i].current.x= i + 5;
		this->cells[i].current.y= 0;	
	}
	this->cells[2].current.x= 4;
	this->cells[2].current.y = 1;
	this->cells[3].current.x= 5;
	this->cells[3].current.y= 1;
}

void Sblock::rotate(){



}

void Sblock::down(){
 	for(int i =0; i <=3; i++){
		this->cells[i].current.y= this->cells[i].current.y +1;

}

}

void Sblock::right(){
	for(int i =0; i <=3; i++){
		this->cells[i].current.x= this->cells[i].current.x +1;

	}

}

void Sblock::left(){
	for(int i =0; i <=3; i++){
		this->cells[i].current.x= this->cells[i].current.x +1;
	}


}

void Sblock::getScore(){}
