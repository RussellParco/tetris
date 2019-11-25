#ifndef BLINDEFFECT
#define BLINDEFFECT
#include "effect.h"
#include "basiceffect.h"


class BlindEffect:public EffectDecorator{
	public:
		BlindEffect(Effect *component);
		void applyEffect(&Board) override;

};

#endif 
