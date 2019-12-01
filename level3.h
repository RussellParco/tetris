#ifndef LEVEL3
#define LEVEL3
#include "level.h"
using namespace std;

class Level3 : public Level{
 public:
        Level3(int seed);
	vector<Block*> createPiece(ifstream& sequence, bool random, int lastBlockCleared)override;	
	~Level3();	
};
#endif 
