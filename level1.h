#ifndef LEVEL1
#define LEVEL1
#include "level.h"
#include <fstream>
class Block;
using namespace std;


class Level1 : public Level{
	public:
	Level1();
        Block* createPiece(ifstream& sequence, bool random, int lastBlockCleared)override;
	~Level1();
};
#endif
