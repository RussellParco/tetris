#ifndef BLINDEFFECT
#define BLINDEFFECT
#include "effectdecorator.h"

class BlindEffect: public EffectDecorator{
	public:
		BlindEffect(Effect *component);
		void applyEffect(Board & board) override;

};

#endif 
