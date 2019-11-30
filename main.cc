#include <string>
#include "game.h"
#include "textCommands.h"
#include <sstream>

using namespace std;

int main(int argsc, char* argsv[]){
	stringstream ss;
	bool text = false;
	int seed = 0;
	string scriptfile1 = "biquadris_sequence1.txt";
	string scriptfile2 = "biquadris_sequence2.txt";
	int startlevel  = 0;

	for(int i = 1; i < argsc; i++){
		if((string)argsv[i] == "-text"){
			text = true;
		}
		else if((string)argsv[i] == "-seed"){
			ss << argsv[i+1];
			ss >> seed;
			i++;
		}
		else if((string)argsv[i] == "-scriptfile1"){
                       	scriptfile1 = argsv[i+1];
                        i++;
                }
 		else if((string)argsv[i] == "-scriptfile2"){
                        scriptfile2 = argsv[i+1];
                        i++;
                }else if((string)argsv[i] == "-startlevel"){
                        ss << argsv[i+1];
                        ss >> startlevel;
                        i++;
                }
	}
	Game *game = new Game(text,seed, scriptfile1, scriptfile2, startlevel);
	game->play();
	return 0;
}
