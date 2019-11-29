#ifndef LEVEL
#define LEVEL

#include <fstream>
using namespace std;

class Block;

class Level{
	public:
	virtual Block* createPiece(const ifstream& sequence, bool random, int lastBlockCleared )=0;
	virtual ~Level() = 0;	
};
#endif 
