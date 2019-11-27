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

void Tblock::rotate(string type){
  float cx = this->cells[2].current.x;
  float cy = this->cells[2].current.y;
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
