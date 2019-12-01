#ifndef LEVEL
#define LEVEL
#include "forceblock.h"
#include "block.h"
#include "iblock.h"
#include "lblock.h"
#include "jblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Level{
	public:
	virtual vector<Block*> createPiece(ifstream& sequence, bool random, int lastBlockCleared )=0;
	virtual ~Level() = default ;	
};
#endif 
