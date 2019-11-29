#include "textCommands.h"
textCommands::textCommands(Game *game) {//for now, default constructor
    vector<string> nam{"left", "right", "down", "clockwise",
                    "counterclockwise", "drop", "levelup",
                    "leveldown",
                    //"norandom",
                    "random",
                    //"sequence",
                    "I","J","L","O","S","Z","T",
                    "restart"};
    names = nam;
    vector<Command*> com{new leftCommand(new baseCommand(game)), new rightCommand(new baseCommand(game)), 
			new downCommand(new baseCommand(game)), new clockwiseCommand(new baseCommand(game)),
			new counterclockCommand(new baseCommand(game)), new dropCommand(new baseCommand(game)), 
			new levelupCommand(new baseCommand(game)), new leveldownCommand(new baseCommand(game)),
                         //new norandomCommand(new baseCommand()),
                         new randomCommand(new baseCommand(game)),
                         //new sequenceCommand(new baseCommand()),
                         new ICommand(new baseCommand(game)), new JCommand(new baseCommand(game)), 
			new LCommand(new baseCommand(game)), new OCommand(new baseCommand(game)), 
			new SCommand(new baseCommand(game)), new ZCommand(new baseCommand(game)), 
			new TCommand(new baseCommand(game)), new restartCommand(new baseCommand(game))};
    commands = com;
}

Command* textCommands::getCommand (const string &name){ //doesn't work with norandom or sequence for now
    vector<string>::iterator nameIt = find(names.begin(), names.end(), name);
    int index = distance(names.begin(), nameIt);
    return commands[index];
}

//maybe for commandDecorator make a function addFileName(string file)
//implemented for sequence and norandom, dummy function for everything else
//getCommand will split any input string with a space and put the second part into addFileName
//as the file
//this way sequence and norandom can be without a file name until given one
//might need rule of 5 here tho if i start to return a copy of the command
