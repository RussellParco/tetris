#include "textCommands.h"
textCommands::textCommands() {//for now, default constructor
    vector<string> nam{"left", "right", "down", "clockwise",
                    "counterclockwise", "drop", "levelup",
                    "leveldown",
                    "norandom",
                    "random",
                    "sequence",
                    "I","J","L","O","S","Z","T",
                    "restart"};
    names = nam;
    vector<Command*> com{new leftCommand(new baseCommand()), new rightCommand(new baseCommand()), 
			new downCommand(new baseCommand()), new clockwiseCommand(new baseCommand()),
			new counterclockCommand(new baseCommand()), new dropCommand(new baseCommand()), 
			new levelupCommand(new baseCommand()), new leveldownCommand(new baseCommand()),
                         new norandomCommand(new baseCommand(), "testfile"),
                         new randomCommand(new baseCommand()),
                         new sequenceCommand(new baseCommand(), "testfile"),
                         new ICommand(new baseCommand()), new JCommand(new baseCommand()), 
			new LCommand(new baseCommand()), new OCommand(new baseCommand()), 
			new SCommand(new baseCommand()), new ZCommand(new baseCommand()), 
			new TCommand(new baseCommand()), new restartCommand(new baseCommand())};
    commands = com;
}

int textCommands::removePrefix(string &name) {
    string prefix = "";
    unsigned long i;
    for(i = 0; i <= name.length() && isdigit(name[i]); i++){
        prefix += name[i];
    }
    name = name.substr(i);
    return prefix.empty() ? 1 : stoi(prefix);
}

Command* textCommands::getCommand (string &name){
    int prefix = removePrefix(name);
    vector<string>::iterator nameIterator = names.begin();
    int matches = 0;
    long index = 0;
    while (nameIterator != names.end()) {
        if (*nameIterator == name){
            matches = 1;
            index = distance(names.begin(), nameIterator);
            break;
        }
        else
            if (nameIterator->find(name) != string::npos) {
            ++matches;
            index = distance(names.begin(), nameIterator);
            cout<<index;
            cout<<"\n";
        }
        ++nameIterator;
    }
    if (matches == 1) { //name input was specific enough to return a specific command
        return commands[index];

        //TODO
        //what command to return in the case of bad input??
        //should we make a new error command?
        //i'll return nullptr for now
    //} else if (matches == 0) { // no command found
    //    return nullptr;
    } else { // too many matches
        return nullptr;
    }
}

//maybe for commandDecorator make a function addFileName(string file)
//implemented for sequence and norandom, dummy function for everything else
//getCommand will split any input string with a space and put the second part into addFileName
//as the file
//this way sequence and norandom can be without a file name until given one
//might need rule of 5 here tho if i start to return a copy of the command
