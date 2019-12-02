#ifndef BASICEFFECT
#define BASICEFFECT
#include "effect.h"


class BasicEffect: public Effect{
	
	public:
	BasicEffect(std::string effectType); 
	void applyEffect(Board &  board);


};




#endif
