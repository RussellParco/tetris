#ifndef TEXTDISPLAY
#define TEXTDISPLAY
#include "display.h"
#include "coord.h"
#include <iostream>
#include <string>

class TextDisplay : public GameDisplay{
	std::string blockStrings[7] = {"IIII", "J\nJJJ", "  L\nLLL", "OO\nOO", " SS\nSS",
					"ZZ\n ZZ", "TTT\n T"};
	public:
	TextDisplay(int height, int width);
	void render()override;
	~TextDisplay() = default;
	std::string getBlockString(char c)const;
friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif 
