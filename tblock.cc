#include "tblock.h"
#include <string>

Tblock::Tblock(char type, int weight): type{type}, weight{weight} {

	for(int i =0; i <= 2; i++){
		this->cells[i].current.x= i + 4;
		this->cells[i].current.y= 0;	
	}
	this->cells[3].current.x= 4;
	this->cells[3],.current.y = 1;
}

void Tblock::rotate(){



}

void Tblock::down(){
 	for(int i =0; i <=3; i++){
		this->cells[i].current.y= this->cells[i].current.y +1;

}

}

void Tblock::right(){
	for(int i =0; i <=3; i++){
		this->cells[i].current.x= this->cells[i].current.x +1;

	}

}

void Tblock::left(){
	for(int i =0; i <=3; i++){
		this->cells[i].current.x= this->cells[i].current.x +1;
	}


}

void Tblock::getScore(){}
