#include "textdisplay.h"
#include <iomanip>
using namespace std;

TextDisplay::TextDisplay(int width, int height):GameDisplay(width, height){}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td){
	//print levels
	out << "Level:\t"<< td.theDisplay[0]->getLevel() << "\t\tLevel:\t" << td.theDisplay[1]->getLevel() << endl;
	//print socres
	out << "Score:\t"<< td.theDisplay[0]->getScore() << "\t\tScore:\t" << td.theDisplay[1]->getScore() << endl;
	for(int i = 0; i < 2; i++){
		for(int w = 0; w < td.width; w++){
			out << "-";
		}
		out << "\t\t";
	}
	
	out << endl;
	for(int r = 0; r < td.height; r++){
		for(int c = 0; c < td.width; c++){
			out << td.theDisplay[0]->getCell(r, c);
		}
		out << "\t\t";
		for(int c = 0; c < td.width; c++){
                        out << td.theDisplay[1]->getCell(r,c);
                }

		out << endl;
	}
	for(int i = 0; i < 2; i++){
		for(int w = 0; w < td.width; w++){
			out << "-";
		}
		out << "\t\t";
	}
	out << endl;
	out << left<< setw(td.width) << "Next:"; 
	out << "\t\t";
	out<< left << setw(td.width) << "Next:"  <<endl;
	string next0 = td.getBlockString(td.theDisplay[0]->getNext());
	string next1 = td.getBlockString(td.theDisplay[1]->getNext());
	
	stringstream ss0;
	stringstream ss1;
	ss0.str(next0);
	ss1.str(next1);
	for(int i = 0; i < 2; i ++){
		next0 = next1 = "";
		getline(ss0, next0);
		getline(ss1, next1);
		out << setw(td.width) << next0;
		out << "\t\t";
		out << next1;
		out <<endl;
	}
	
	return out;
}

void TextDisplay::render(){
	cout << *this;
}

string TextDisplay::getBlockString(char c)const{
	if(c == 'I'){
		return TextDisplay::blockStrings[0];
	}else if(c == 'J'){
		return TextDisplay::blockStrings[1];
	}else if(c == 'L'){
		return  TextDisplay::blockStrings[2];
	}else if(c == 'O'){
		return  TextDisplay::blockStrings[3];
	}else if(c == 'S'){
		return  TextDisplay::blockStrings[4];
	}else if(c == 'Z'){
		return  TextDisplay::blockStrings[5];
	}else{
		return  TextDisplay::blockStrings[6];
	}
}
