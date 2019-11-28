#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay(int width, int height):gridSize{n}{
	theDisplay.resize(n);

	for(int r = 0; r < n; r++){
		for(int c = 0; c < n; c++){
			theDisplay[r].push_back(' ');
		}
	}
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td){
	//print levels
	out << "Level:\t"<< level[0] << "\t\tLevel:\t" << level[1] << endl;
	//print socres
	out << "Score:\t"<< score[0] << "\t\tScore:\t" << score[1] << endl;
	for(int i = 0; i < 2; i++){
		for(int w = 0; w < td.width; c++){
			out << "-";
		}
		out << "\t\t" << endl;
	}
	

	for(int r = 0; r < td.height; r++){
		for(int c = 0; c < td.width; c++){
			out << td.theDisplay[0][r][c];
		}
		out << "\t\t"
		for(int c = 0; c < td.width; c++){
                        out << td.theDisplay[1][r][c];
                }

		out << std::endl;
	}
	return out;
}

void TextDisplay::updateLevels(int levels[]){
        this->level = level;
}

void TextDisplay::updateScores(int scores[]){
	this->score = scores;
}

void TextDisplay::update(char content, int x, int y, int player){
	theDisplay[player][x][y] = content;
}
