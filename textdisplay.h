#ifndef TEXTDISPLAY
#define TEXTDISPLAY
#include "display.h"
#include "coord.h"
#include <iostream>

class TextDisplay : public Display{
	public:
	TextDisplay(int height, int width);
	void render()override;
	~TextDisplay() = default;
friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif 
