#ifndef DISPLAY
#define DISPLAY
#include "display.h"
#include "coord.h"
#include <vector>
#include "playerdisplay.h"

class Display{

	protected:
		std::vector<PlayerDisplay> theDisplay;
		int height;
		int width;	
		public:
		Display(int height, int width);
		PlayerDisplay* addPlayer(int level);
		virtual void render() = 0;
		virtual ~Display() = default;

};

#endif 
