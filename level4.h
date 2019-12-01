#ifndef LEVEL4
#define LEVEL4
#include "level.h"
using namespace std;


class Level4 : public Level{

	public:
	Level4(int seed);
        vector<Block*> createPiece(ifstream& sequence, bool random, int lastBlockCleared)override;
	~Level4();
};
#endif
