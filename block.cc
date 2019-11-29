#include "block.h"
using namespace std;

vector<Cell> Block::getCells(){
	return cells;
}


void Block::rotate(string type){
Coord temp = cells[0].getCoord();
int top = temp.y;
int left = temp.x;

	for(int i=0; i <= 3; i++){
		if(cells[i].getCoord().y >= top){
			top = cells[i].getCoord().y;
		}
	}
	for(int i=0; i <= 3; i++){
		if(cells[i].getCoord().x <= left){
			left = cells[i].getCoord().x;
		}
	}


 
  int cx = 0;
  int cy = 0;
  int  s = 1;
  int  c = 0;
        for(int i = 0; i<=3; i++){

        // rotate point
	if(type == "clockwise"){
         int xnew = cells[i].getCoord().x * c - cells[i].getCoord().y * s;
         int ynew = cells[i].getCoord().x * -1 * s + cells[i].getCoord().y * c;

		  // translate point back:
       	 	 ynew = ynew + top;
		Coord newCoord {xnew, ynew};
		cells[i].setCoord(newCoord);

	}
	else  {
	int xnew = cells[i].getCoord().x * c - cells[i].getCoord().y * s;
	int ynew = cells[i].getCoord().x * s + cells[i].getCoord().y * c;
	  // translate point back:
	xnew = xnew + left;
	Coord newCoord {xnew, ynew};
	cells[i].setCoord(newCoord);
	}
          
        }

}

void Block::down(){
 	for(int i =0; i <= 3; i++){
		int xnew =0;
		int ynew = 0;
		ynew = cells[i].getCoord().y + 1;
		xnew = cells[i].getCoord().x;
		Coord newCoord {xnew, ynew};
		cells[i].setCoord(newCoord);
			
}

}

void Block::right(){
	for(int i =0; i <= 3; i++){
		int xnew =0;
		int ynew = 0;
		xnew= cells[i].getCoord().x + 1;
		ynew = cells[i].getCoord().y;
		Coord newCoord {xnew, ynew};
		cells[i].setCoord(newCoord);
	}

}

void Block::left(){
	for(int i =0; i <=3; i++){
		int xnew;
		int ynew;
		xnew= cells[i].getCoord().x - 1;
		ynew = cells[i].getCoord().y;
		Coord newCoord {xnew, ynew};
		cells[i].setCoord(newCoord);
}


}

int Block::getScore(){
	int score = level + 1;
	score = score * score;
	return score;
}




