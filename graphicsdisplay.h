#ifndef GRAPHICSDISPLAY
#define GRAPHICSDISPLAY
#include "display.h"
#include "window.h"


class GraphicsDisplay : public GameDisplay{
	int blockColours[7][8]{{0,0,0,0,5,5,5}, {8,0,0,0,8,8,8,0},
		{0,0,4,0,4,4,4,0},{0,3,3,0,3,3,0,0},{2,2,0,0,0,2,2,0},
		{6,6,0,0,6,6,0,0},{7,7,7,0,0,7,0,0}};
	Xwindow window;
	int getColourSeq(char c);
	public:
	GraphicsDisplay(int height, int width);
	void render()override;
	~GraphicsDisplay() = default;

};
#endif 
