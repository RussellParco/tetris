#ifndef EFFECTDECORATOR
#define EFFECTDECORATOR
#include "basiceffect.h"


class EffectDecorator: public Effect{
	protected:	
		Effect component;
	public:
	Decorator(Effect *component);
	virtual ~Decorator;
};



#endif

