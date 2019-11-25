#ifndef EFFECT
#define EFFECT
#include "board.h"

class Effect{
	int dropRate;
	bool blind;
	bool force;
	Block forceBlock{};

	public:
		virtual void applyEffect(&Board board) = 0;	
		virtual ~Effect;

};




#endif 
