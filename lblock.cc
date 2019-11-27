#include "lblock.h"
#include <string>

Lblock::Lblock(char type, int weight): type{type}, weight{weight} {

	for(int i =0; i <= 2; i++){
		this->cells[i].current.x= i + 5;
		this->cells[i].current.y= 1;	
	}
	this->cells[3].current.x= 7;
	this->cells[3].current.y = 0;
}

void Lblock::rotate(string type){



}

void Lblock::down(){
 	for(int i =0; i <=3; i++){
		this->cells[i].current.y= this->cells[i].current.y +1;

}

}

void Lblock::right(){
	for(int i =0; i <=3; i++){
		this->cells[i].current.x= this->cells[i].current.x +1;

	}

}

void Lblock::left(){
	for(int i =0; i <=3; i++){
		this->cells[i].current.x= this->cells[i].current.x +1;
	}


}

void Lblock::getScore(){}
