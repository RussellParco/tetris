#ifndef HEAVYEFFECT
#ifndef HEAVYEFFECT
#include "effect.h"
#include "basiceffect.h"

class HeavyEffect:public EffectDecorator{
	public:	
	HeavyEffect(Effect * component);
	void applyEffect(Board & board) override; 



};



#endif
