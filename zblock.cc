#include "zblock.h"
#include <string>

Zblock::Zblock(char type, int weight): type{type}, weight{weight} {

	for(int i =0; i <= 1; i++){
		this->cells[i].current.x= i + 4;
		this->cells[i].current.y= 0;	
	}
	this->cells[2].current.x= 5;
	this->cells[2].current.y = 1;
	this->cells[3].current.x= 6
	this->cells[3].current.y= 1;
}

void Tblock::rotate(){



}

void Zblock::down(){
 	for(int i =0; i <=3; i++){
		this->cells[i].current.y= this->cells[i].current.y +1;

}

}

void Zblock::right(){
	for(int i =0; i <=3; i++){
		this->cells[i].current.x= this->cells[i].current.x +1;

	}

}

void Zblock::left(){
	for(int i =0; i <=3; i++){
		this->cells[i].current.x= this->cells[i].current.x +1;
	}


}

void Zblock::getScore(){}
