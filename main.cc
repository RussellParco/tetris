int main(int arcsc, char* argsv[]){
	bool text = false;
	int seed = 0;
	string scriptfile1;
	string scriptfile2;
	int startlevel  = 0;
	for(int i = 1; i < argsc; i++){
		if(argsv[i] == "-text"){
			text = true;
		}
		else if(argsv[i] == "-seed"){
			ss << argsv[i+1];
			ss >> seed;
			i++;
		}
		else if(argsv[i] == "-scriptfile1"){
                       	scriptfile1 = argsv[i+1];
                        i++;
                }
 		else if(argsv[i] == "-scriptfile2"){
                        scriptfile2 = argsv[i+1];
                        i++;
                }else if(argsv[i] == "-startlevel"){
                        ss << argsv[i+1];
                        ss >> startlevel;
                        i++;
                }
	}
	Game *game = new Game(text,seed, scriptfile1, scriptfile2);
	game->play();
	return 0;
}
