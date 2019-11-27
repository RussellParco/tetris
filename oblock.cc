#include "oblock.h"
#include <string>

Oblock::Oblock(char type, int weight): type{type}, weight{weight} {

	for(int i =0; i <= 1; i++){
		this->cells[i].current.x= i + 5;
		this->cells[i].current.y= 0;	
	}
	this->cells[2].current.x= 5;
	this->cells[2].current.y = 1;
	this->cells[3].current.x= 6
	this->cells[3].current.y= 1;
}

void Oblock::rotate(string type){



}

void Oblock::down(){
 	for(int i =0; i <=3; i++){
		this->cells[i].current.y= this->cells[i].current.y +1;

}

}

void Oblock::right(){
	for(int i =0; i <=3; i++){
		this->cells[i].current.x= this->cells[i].current.x +1;

	}

}

void Oblock::left(){
	for(int i =0; i <=3; i++){
		this->cells[i].current.x= this->cells[i].current.x +1;
	}


}

void Oblock::getScore(){}
