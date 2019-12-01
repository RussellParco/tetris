#include "effectdecorator.h"

EffectDecorator::EffectDecorator(Effect * component): component{component} {}

EffectDecorator:: ~EffectDecorator() {delete component;}
