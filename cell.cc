#include "cell.h"

Cell::Cell(Coord current, char content): current{current}, content{content} {}



char  Cell::getContent(){
	return content;
}

void Cell::setContent(char letter){	
	this->content= letter;	
	
}

Coord Cell::getCoord(){
	Coord temp;	
	temp.x = this->current.x;
	temp.y = this->current.y;
	return temp;	
}

void Cell::setCoord(Coord temp){
	this->current.x = temp.x;
	this->current.y = temp.y;		
}

