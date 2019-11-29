#ifndef TEXTDISPLAY
#define TEXTDISPLAY
#include "display.h"
#include "coord.h"
#include <iostream>

class TextDisplay : public Display{
	TextDisplay(int height, int width);

friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif 
