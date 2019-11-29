#ifndef LEVEL3
#define LEVEL3
#include "level.h"
using namespace std;

class Level3 : public Level{
 public:
        Block* createPiece(const ifstream& sequence, bool random, int lastBlockCleared)override;	
	
};
#endif 
