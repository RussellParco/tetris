#ifndef EFFECTDECORATOR
#define EFFECTDECORATOR
#include "basiceffect.h"


class EffectDecorator: public Effect{
	protected:	
		Effect *component;
	public:
	EffectDecorator(Effect *component);
	virtual ~EffectDecorator();
};



#endif

