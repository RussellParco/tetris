#ifndef LEVEL
#define LEVEL
#include "iblock.h"
#include "lblock.h"
#include "jblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include <iostream>


#include <fstream>
using namespace std;

class Block;

class Level{
	public:
	virtual Block* createPiece(ifstream& sequence, bool random, int lastBlockCleared )=0;
	virtual ~Level() = default ;	
};
#endif 
