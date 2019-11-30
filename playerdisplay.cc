#include "playerdisplay.h" 

PlayerDisplay::PlayerDisplay(int width,int height, int level):
width{width}, level{level}, score{0}
{
	std::cout << width<< "," << height << std::endl;
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
std::cout << "inside update" << width << ","<< theDisplay.size()<< ","<< c.x << ","<< c.y<< std::endl;
	
	theDisplay[c.y*width + c.x] = content;

	std::cout << "inside update" << std::endl;
}
char PlayerDisplay::getCell(int row, int col)const{
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
