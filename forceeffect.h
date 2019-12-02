#ifndef FORCEEFFECT
#define FORCEEFFECT
#include "effectdecorator.h"

class ForceEffect:public EffectDecorator{
	public:
		ForceEffect(Effect *component);
		void applyEffect(Board & board) override;

};

#endif

