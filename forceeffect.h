#ifndef FORCEEFFECT
#define FORCEEFFECT
#include "effect.h"
#include "basiceffect.h"


class ForceEffect:public EffectDecorator{
	public:
		ForceEffect(Effect *component);
		void applyEffect(&Board) override;

};

#endif

