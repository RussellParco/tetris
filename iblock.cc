#include "iblock.h"
#include <string>

Iblock::Iblock(char type, int weight): type{type}, weight{weight} {

	for(int i =0; i <= 3; i++){
		this->cells[i].current.x= i + 5;
		this->cells[i].current.y= 1;	
	}
}

void Iblock::rotate(string type){
  float cx = this->cells[0].current.x;
  float cy = this->cells[0].current.y;
  float s = 1;
  float c = 0;
        for(int i = 0; i<=3; i++){
         this->cells[i]current.x -= cx;
         this->cells[i]current.y -= cy;

        // rotate point
	if(type == "clockwise"){
         float xnew = this->cells[i].current.x * c - this->cells[i].current.y * s;
         float ynew = this->cells[i].current.x * -1 * s + this->cells[i].current.y * c;

		  // translate point back:
      		   this->cells[i].current.x = xnew + cx;
       	 	 this->cells[i].current.y = ynew + cy;

	}
	else  {
	float xnew = p.x * c - p.y * s;
	float ynew = p.x * s + p.y * c;
	  // translate point back:
	 this->cells[i].current.x = xnew + cx;
      	this->cells[i].current.y = ynew + cy;

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
