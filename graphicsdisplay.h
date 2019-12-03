#ifndef GRAPHICSDISPLAY
#define GRAPHICSDISPLAY
#include "display.h"
#include "window.h"


class GraphicsDisplay : public GameDisplay{
	Xwindow window;
	public:
	GraphicsDisplay(int height, int width);
	void render()override;
	~GraphicsDisplay() = default;

};
#endif 
