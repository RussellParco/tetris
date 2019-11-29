#ifndef LEVEL0
#define LEVEL0
#include "level.h"
#include <fstream>
using namespace std;

class Block;

class Level0 : public Level{
	public:
	Block* createPiece(const ifstream& sequence, bool random, int lastBlockCleared)override;	
};
#endif
