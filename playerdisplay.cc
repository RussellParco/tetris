
#include "playerdisplay.h" 
#include  <iomanip>
PlayerDisplay::PlayerDisplay(int width,int height, int level):
width{width}, height{height}, level{level}, score{0}, blind{false}
{
	theDisplay.resize(width*height);
	for(int i = 0; i < width*height; i++){
		theDisplay[i] = (' ');
	}
}
void PlayerDisplay::updateScore(int score){
	this->score = score;
}
void PlayerDisplay::updateLevel(int level){
	this->level =level;
}
void PlayerDisplay::update(char content, Coord c){
	
	theDisplay[(c.y * width) + c.x ] = content;
}
char PlayerDisplay::getCell(int row, int col)const{
	
	if(blind && col >=2 && col <= 8 && row >= 2 && row <= 11){
		return '?';
	}
	return theDisplay[row *width + col];
}

int PlayerDisplay::getLevel()const{
	return level;
}

int PlayerDisplay::getScore()const{
        return score;
}

void PlayerDisplay::swapRow(int row1, int row2){
	for(int i = 0; i < width; i++){
		std::swap(theDisplay[row1*width + i], theDisplay[row2*width + i]);
	}
}
void PlayerDisplay::restart(){
	for(int i = 0; i < width*height; i++){
                theDisplay[i] = (' ');
        }
}
	
void PlayerDisplay::setBlind(bool flag){
	blind = flag;	
}
void PlayerDisplay::updateNext(char blockType){
	next = blockType;
}
char PlayerDisplay::getNext(){
	return next;
}
PlayerDisplay::~PlayerDisplay(){}
