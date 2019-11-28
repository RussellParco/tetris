#ifndef LEVEL
#define LEVEL
class Level{
	virtual Block* createPiece(ifstream& sequence, bool random, int lastBlockCleared )=0;
	virtual ~Block() = 0;	
};
#endif 
