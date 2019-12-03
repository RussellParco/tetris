#include "forceeffect.h"
	

ForceEffect::ForceEffect(Effect * component): EffectDecorator{component} {}

void ForceEffect::applyEffect(Board & board){
	char c; 
	std::cin >> c;
	if(c == 'I'){
		board.I();
	}
	else if(c == 'J'){
		board.J();
	}
	else if(c == 'L'){
		board.L();
	}
	else if(c == 'O'){
		board.O();
	
	}
	else if(c == 'S'){
		board.S();
	}
	else if(c == 'Z'){
		board.Z();

	}
	else if(c == 'T' ){
		board.T();
	
	}
	else{
		std::cout << "Invalid Block"<< std::endl;
	} 
}
