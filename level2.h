#ifndef LEVEL2
#define LEVEL2

#include "level.h"
using namespace std;

class Level2 : public Level{
	public:
        Block* createPiece(const ifstream& sequence, bool random, int lastBlockCleared)override;
};
#endif
