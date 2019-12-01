#include "block.h"
using namespace std;


Block::Block(char type,int width, int height, int weight, int level): type{type}, width{width}, height{height}, weight{weight}, level{level}{}

vector<Cell> Block::getCells(){
	return cells;
}


void Block::rotate(string type){
Coord temp = cells[0].getCoord();
int bottom = temp.y;
int left = temp.x;

	for(int i=0; i <= 3; i++){
		if(cells[i].getCoord().y <= bottom){
			bottom = cells[i].getCoord().y;
		}
	}
	for(int i=0; i <= 3; i++){
		if(cells[i].getCoord().x <= left){
			left = cells[i].getCoord().x;
		}
	}


 
 // int cx = 0;
 // int cy = 0;
 // int  s = 1;
  //int  c = 0;

	int xnew=0;
	int ynew=0;
        for(int i = 0; i<=3; i++){
		xnew = cells[i].getCoord().x - left;
		ynew = cells[i].getCoord().y - bottom;	
		//int xnew = cells[i].getCoord().x - left;
	//	int ynew = cells[i].getCoord().y - top;
        // rotate point
		
		if(type == "clockwise"){
 	
			int temp = xnew;
			 xnew =  -1 * ynew;
			 ynew = temp;
			 xnew += (height - 1);
	        
		
		  // translate point back:
       	 //	 ynew = ynew + top;
	//	Coord newCoord {xnew, ynew};
	//	cells[i].setCoord(newCoord);

		}
		else  {
         		int temp = xnew;
			xnew = ynew;
         		ynew = -1 * temp;
			ynew += (width - 1);
	
		}
	  // translate point back:
	

		xnew = xnew + left;
		ynew = ynew + bottom;
		Coord newCoord {xnew, ynew};
		cells[i].setCoord(newCoord);          
}
		int set = width;
		width = height;
		height = set; 
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


bool Block::remove(int cellIndex){
	cells.erase(cells.begin() + cellIndex);
	if(cells.empty()){
		return true;
	}
	return false;
}



Block::~Block(){}

int Block::getWeight(){
	return weight;
}
void Block::setWeight(int addWeight){
	weight += addWeight;	
}

int Block::getHeight(){
	return height;
}

int Block::getWidth(){
	return width;	
}


