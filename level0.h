#ifndef LEVEL0
#define LEVEL0
class Level0 : Level{
	*Block createPiece(ifstream& sequence, bool random, int lastBlockCleared )override;	
};
#endif
