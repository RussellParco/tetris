#ifndef GRAPHICSDISPLAY
#define GRAPHICSDISPLAY
#include "display.h"


class GraphicsDisplay{
	vector<int> theDisplay();
	public:
		void render() override;
		void updateDisplay() override;
};


#endif 
