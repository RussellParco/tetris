#ifndef EFFECT
#define EFFECT
#include "board.h"
#include <string>
class Effect{
	public:
		virtual void applyEffect(Board & board) = 0;	
		virtual ~Effect() = default;
};




#endif 
