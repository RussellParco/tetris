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
//    vector<Command*> com{new leftCommand(new baseCommand(), 1), new rightCommand(new baseCommand(), 1),
//			new downCommand(new baseCommand()), new clockwiseCommand(new baseCommand()),
//			new counterclockCommand(new baseCommand()), new dropCommand(new baseCommand()),
//			new levelupCommand(new baseCommand()), new leveldownCommand(new baseCommand()),
//                         new norandomCommand(new baseCommand(), "testfile"),
//                         new randomCommand(new baseCommand()),
//                         new sequenceCommand(new baseCommand(), "testfile"),
//                         new ICommand(new baseCommand()), new JCommand(new baseCommand()),
//			new LCommand(new baseCommand()), new OCommand(new baseCommand()),
//			new SCommand(new baseCommand()), new ZCommand(new baseCommand()),
//			new TCommand(new baseCommand()), new restartCommand(new baseCommand())};
//    commands = com;
//    vector<string> specNam{"heavy", "blind", "force"};
//    specNames = specNam;
//    vector<Command*> specCom{new heavyCommand(new baseCommand()), new blindCommand(new baseCommand()), new forceCommand(new baseCommand())};\
//    specCommands = specCom;
}

int textCommands::removePrefix(string &name) {
    string prefix;
    unsigned long i;
    for(i = 0; i <= name.length() && isdigit(name[i]); i++){
        prefix += name[i];
    }
    name = name.substr(i);
    return prefix.empty() ? 1 : stoi(prefix);
}

Command* textCommands::addCommand(const string &name, const int &prefix, Command* command, istream &in){
    if (name == "left"){
        command = new leftCommand(command, prefix);
    }
    else if (name == "right"){
        command = new rightCommand(command, prefix);
    }
    else if (name == "restart"){
        command = new restartCommand(command);
    }
    else if (name == "sequence"){
        command = new sequenceCommand(command, in);
    }
    else if (name == "norandom"){
        command = new norandomCommand(command, in);
    }
    else if (name == "random"){
        command = new randomCommand(command);
    }
    else{
        for (int i = 0; i < prefix; i++){
            if (name == "down"){
                command = new downCommand(command);
            }
            else if (name == "clockwise"){
                command = new clockwiseCommand(command);
            }
            else if (name == "counterclockwise"){
                command = new counterclockCommand(command);
            }
            else if (name == "drop"){
                command = new dropCommand(command);
            }
            else if (name == "levelup"){
                command = new levelupCommand(command);
            }
            else if (name == "leveldown"){
                command = new leveldownCommand(command);
            }
            else if (name == "I"){
                command = new ICommand(command);
            }
            else if (name == "J"){
                command = new JCommand(command);
            }
            else if (name == "L"){
                command = new LCommand(command);
            }
            else if (name == "O"){
                command = new OCommand(command);
            }
            else if (name == "S"){
                command = new SCommand(command);
            }
            else if (name == "Z"){
                command = new ZCommand(command);
            }
            else if (name == "T"){
                command = new TCommand(command);
            }
        }
    }
    return command;
}

int textCommands::formatCommandName(string &name){//takes in a shorthand form of a command and returns the number of matches, also changes the name to the full name of the last matched command
    int matches = 0;
    long index = 0;
    auto nameIterator = names.begin();
    while (nameIterator != names.end()) {
        if (*nameIterator == name){
            matches = 1;
            index = distance(names.begin(), nameIterator);
            break;
        }
        else if (nameIterator->find(name) != string::npos) {
            ++matches;
            index = distance(names.begin(), nameIterator);
        }
        ++nameIterator;
    }
    name = names[index];
    return matches;
}

Command* textCommands::getCommand (string &name){
    int prefix = removePrefix(name);
    int matches = formatCommandName(name);
    if (matches == 1) { //name input was specific enough to return a specific command
        return addCommand(name, prefix);

        //TODO
        //what command to return in the case of bad input??
        //should we make a new error command?
        //i'll return nullptr for now
    } else if (matches == 0) { // no command found
        cerr << "no command matches this name";
        return nullptr;
    } else { // too many matches
        cerr << "name is not specific enough";
        return nullptr;
    }
}

Command* textCommands::createSequence(const string &filename, Command *command) {
    ifstream inFile;
    string input;
    int prefix = 1;
    inFile.open(filename, ios::in);
    if (!inFile){
        cerr << "no such file\n";
    }
    while(inFile >> input){
        prefix = removePrefix(input);
        if(formatCommandName(input) == 1){
            command = addCommand(input, prefix, command, inFile);
        }
    }
    inFile.close();
    return command;
}

//Command* textCommands::getSpecialAction(string &name) {
//    vector<string>::iterator nameIterator = specNames.begin();
//    int matches = 0;
//    long index = 0;
//    while (nameIterator != specNames.end()) {
//        if (*nameIterator == name){
//            matches = 1;
//            index = distance(specNames.begin(), nameIterator);
//            break;
//        }
//        else
//        if (nameIterator->find(name) != string::npos) {
//            ++matches;
//            index = distance(specNames.begin(), nameIterator);
//        }
//        ++nameIterator;
//    }
//    if (matches == 1) { //name input was specific enough to return a specific command
//        return specCommands[index];
//    }
//    else { // no match or too many matches
//        return nullptr;
//    }
//}
