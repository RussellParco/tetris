#ifndef HEAVYEFFECT
#define HEAVYEFFECT
#include "effectdecorator.h"


class HeavyEffect:public EffectDecorator{
	public:	
	HeavyEffect(Effect * component);
	void applyEffect(Board & board) override; 



};



#endif
