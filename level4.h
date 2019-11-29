#ifndef LEVEL4
#define LEVEL4
#include "level.h"
using namespace std;


class Level4 : public Level{
	public:
        Block* createPiece(const ifstream& sequence, bool random, int lastBlockCleared)override;
	
};
#endif
