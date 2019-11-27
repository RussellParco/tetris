#include "textCommands.h"
textCommands::textCommands() {//for now, default constructor
    vector<string> nam{"left", "right", "down", "clockwise",
                    "counterclockwise", "drop", "levelup",
                    "leveldown",
                    //"norandom",
                    "random",
                    //"sequence",
                    "I","J","L","O","S","Z","T",
                    "restart"};
    names = nam;
    vector<Command*> com{new leftCommand(new baseCommand()), new rightCommand(new baseCommand()), new downCommand(new baseCommand()), new clockwiseCommand(new baseCommand()),
                         new counterclockCommand(new baseCommand()), new dropCommand(new baseCommand()), new levelupCommand(new baseCommand()),
                         new leveldownCommand(new baseCommand()),
                         //new norandomCommand(new baseCommand()),
                         new randomCommand(new baseCommand()),
                         //new sequenceCommand(new baseCommand()),
                         new ICommand(new baseCommand()), new JCommand(new baseCommand()), new LCommand(new baseCommand()), new OCommand(new baseCommand()), new SCommand(new baseCommand()), new ZCommand(new baseCommand()), new TCommand(new baseCommand()),
                         new restartCommand(new baseCommand())};
    commands = com;
}

Command getCommand::textCommands (const string &name){ //doesn't work with norandom or sequence for now
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
