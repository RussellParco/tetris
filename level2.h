#ifndef LEVEL2
#define LEVEL2

#include "level.h"
using namespace std;

class Level2 : public Level{
	public:
	Level2();
        Block* createPiece(ifstream& sequence, bool random, int lastBlockCleared)override;
	~Level2();
};
#endif
