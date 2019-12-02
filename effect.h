#ifndef EFFECT
#define EFFECT
#include "board.h"
#include <string>
class Effect{
	std::string effectType;	
	public:
		virtual void applyEffect(Board & board) = 0;	
		virtual ~Effect();
		virtual std::string getType();
};




#endif 
