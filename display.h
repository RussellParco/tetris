#ifndef DISPLAY
#define DISPLAY
#include "display.h"
#include "coord.h"
#include <vector>
#include "playerdisplay.h"

class GameDisplay{

	protected:
		std::vector<PlayerDisplay*> theDisplay;
		int height;
		int width;	
		public:
		GameDisplay(int height, int width);
		PlayerDisplay* addPlayer(int level);
		void restart();
		virtual void render() = 0;
		virtual ~GameDisplay();

};

#endif 
