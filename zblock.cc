#include "zblock.h"
#include <string>

Zblock::Zblock(char type, int weight): type{Z}, weight{weight} {

	for(int i =0; i <= 1; i++){
		this->cells[i].current.x= i + 4;
		this->cells[i].current.y= 0;	
	}
	this->cells[2].current.x= 5;
	this->cells[2].current.y = 1;
	this->cells[3].current.x= 6
	this->cells[3].current.y= 1;

	for(int i =0; i <=3; i++){
		this->cells[i].content = 'Z';
	}
}

void Zblock::rotate(string type){
int top = this->ells[0].current.y;
int left = this->cells[0].current.x;

	for(int i=0; i <= 3; i++){
		if(testCells[i].current.y >= top){
			top = testCells[i].current.y;
		}
	}
	for(int i=0; i <= 3; i++){
		if(testCells[i].current.x <= left){
			left = testCells[i].current.x;
		}
	}


 
  int cx = 0;
  int cy = 0;
  int  s = 1;
  int  c = 0;
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
	int xnew = this->cells[i]current.x * c - this->cells[i].current.y * s;
	int ynew = this->cells[i].current.x * s + this->cells[i].current.y * c;
	  // translate point back:
	 this->cells[i].current.x = xnew + left;
      	this->cells[i].current.y = ynew + top;

	}
          
        }

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
