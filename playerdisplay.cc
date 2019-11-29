#include "playerdisplay.h" 

PlayerDisplay::PlayerDisplay(int width, int height, int level):
width{width}, height{height}, level{level}, score{0}
{
	for(int i = 0; i < width*height; i++){
		theDisplay.emplace_back(' ');
	}
}
void PlayerDisplay::updateScore(int score){
	this->score = score;
}
void PlayerDisplay::updateLevel(int level){
	this->level =level;
}
void PlayerDisplay::update(char content, Coord c){
	theDisplay[c.y*width + c.x] = content;
}
char PlayerDisplay::getCell(int row, int col)const{
	return theDisplay[row*width + col];
}

int PlayerDisplay::getLevel()const{
	return level;
}

int PlayerDisplay::getScore()const{
        return score;
}

