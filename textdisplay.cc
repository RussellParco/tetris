#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(int width, int height):Display(width, height){}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td){
	//print levels
	out << "Level:\t"<< td.theDisplay[0].getLevel() << "\t\tLevel:\t" << td.theDisplay[1].getLevel() << endl;
	//print socres
	out << "Score:\t"<< td.theDisplay[0].getScore() << "\t\tScore:\t" << td.theDisplay[1].getScore() << endl;
	for(int i = 0; i < 2; i++){
		for(int w = 0; w < td.width; w++){
			out << "-";
		}
		out << "\t\t" << endl;
	}
	

	for(int r = 0; r < td.height; r++){
		for(int c = 0; c < td.width; c++){
			out << td.theDisplay[0].getCell(r, c);
		}
		out << "\t\t";
		for(int c = 0; c < td.width; c++){
                        out << td.theDisplay[1].getCell(r,c);
                }

		out << std::endl;
	}
	return out;
}


