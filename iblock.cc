#include "iblock.h"
#include <string>

Iblock::Iblock(char type, int weight): type{type}, weight{weight} {

	for(int i =0; i <= 3; i++){
		this->cells[i].current.x= i + 5;
		this->cells[i].current.y= 1;	
	}
}

void Iblock::rotate(string type){
Vector<Cell> newCells(4);
int width= 4
int height=1 

	for (int i =0; i <= width; i++){

		for(int j= 0; j <= height; j++){
			newCells[i * height + j] = this->cells
			
	}
} 


}

void Iblock::down(){
 	for(int i =0; i <=3; i++){
		this->cells[i].current.y= this->cells[i].current.y +1;
			
}

}

void Iblock::right(){
	for(int i =0; i <=3; i++){
		this->cells[i].current.x= this->cells[i].current.x +1;

	}

}

void Iblock::left(){
	for(int i =0; i <=3; i++){
		this->cells[i].current.x= this->cells[i].current.x +1;
	}


}

void Iblock::getScore(){}
