#include "blindeffect.h"

BlindEffect::BlindEffect(Effect * component): EffectDecorator{component} {}

void BlindEffect::applyEffect(Board & board){
	board.setBlind(true);
 	 
}
