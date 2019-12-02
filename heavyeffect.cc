#include "heavyeffect.h"

HeavyEffect::HeavyEffect(Effect * component): EffectDecorator{component} {}

void HeavyEffect::applyEffect(Board & board){
		Block *currBlock = board.getActive(); 
		int currWeight = currBlock->getWeight();
		int newWeight = currWeight + 2;
		currBlock->setWeight(newWeight);
}



  
