#include "blindeffect.h"

BlindEffect::BlindEffect(Effect * component): Decorator{component} {}

void BlindEffect::applyEffect(Board & board){
	for(int cx= 2; cw <= 8; cx++){	
		for(int cy= 2; cy <= 11; cy ++)	{
			Coord newCoord {cx , cy};
			board->updateDisplays('?', newCoord);
		}
	} 	
}

