#include "block.h"
#include <string>



Block::Block(char type, int weight): type{type}, weight{weight}{

	if(type == 'I'){
		for (int i = 0; i <= 3; i++ ){
		this->cells[i].current.x = 5 + i ;
		this->cells[i].current.y = 0;
		}
	}


	else if (type == 'J'){
		this->cells[0].current.x = 5;
		this->cells[0].current.y=0;
		this->cells[1].current.x= 5;
		this->cells[1].current.y = 1;
		this->current[2].current.x = 6;
		this->current[2].current.y = 1;
		this->current[3].current.x = 7;
		this->current[3].current.y = 1;	
	}
	
	else if (type == 'L'){

		}

	else if (type == 'O'){
		this->blockGrid[8].content = type;
		this->blockGrid[9].content = type;
		this->blockGrid[12].content = type;
		this->blockGrid[13].content = type;
	}
	
	else if (type == 'S'){
		this->blockGrid[9].content = type;
		this->blockGrid[10].content = type;
		this->blockGrid[12].content = type;
		this->blockGrid[13].content = type;
	}

	else if (type == 'Z'){
		this->blockGrid[8].content = type;
		this->blockGrid[10].content = type;
		this->blockGrid[12].content = type;
		this->blockGrid[13].content = type;

	}

	else if (type == 'T'){
		for(int i= 8; i <= 10; i++){
			this->blockGrid[i].content = type;
			this->blockGrid[i].content = type;
			this->blockGrid[i].content = type;

		}
		this->blockGrid[13].content = type;
	}	

	else{
		// invalid input

	}

}

void Block::rotate(string type){
	if(type == "clockwise"){
	
	}
	else if (type == anticlockwise){

	}
}









		
