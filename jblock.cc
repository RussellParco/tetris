#include "jblock.h"
#include <string>

Jblock::Jblock(char type, int weight): type{type}, weight{weight} {

	for(int i =0; i <= 2; i++){
		this->cells[i].current.x= i + 5;
		this->cells[i].current.y= 1;	
	}
	this->cells[3].current.x= 5;
	this->cells[3].current.y = 0;
}

void Jblock::rotate(string type){



}

void Jblock::down(){
 	for(int i =0; i <=3; i++){
		this->cells[i].current.y= this->cells[i].current.y +1;

}

}

void Jblock::right(){
	for(int i =0; i <=3; i++){
		this->cells[i].current.x= this->cells[i].current.x +1;

	}

}

void Jblock::left(){
	for(int i =0; i <=3; i++){
		this->cells[i].current.x= this->cells[i].current.x +1;
	}


}

void Jblock::getScore(){}
