//
// Created by Leo on 11/25/2019.
//

#ifndef TEXTCOMMANDS_H
#define TEXTCOMMANDS_H

#include <fstream>
#include <iostream>
#include "baseCommand.h"
#include "leftCommand.h"
#include "rightCommand.h"
#include "downCommand.h"
#include "clockwiseCommand.h"
#include "counterclockCommand.h"
#include "dropCommand.h"
#include "levelupCommand.h"
#include "leveldownCommand.h"
#include "norandomCommand.h"
#include "randomCommand.h"
#include "sequenceCommand.h"
#include "ICommand.h"
#include "JCommand.h"
#include "LCommand.h"
#include "OCommand.h"
#include "SCommand.h"
#include "ZCommand.h"
#include "TCommand.h"
#include "restartCommand.h"
//#include "heavyCommand.h"
//#include "blindCommand.h"
//#include "forceCommand.h"
#include <vector>
#include <algorithm>


using namespace std;

class textCommands {
    vector<string> names;
    //vector<string> specNames;
    //vector<Command*> commands;
    //vector<Command*> specCommands;
    int removePrefix(string &name);
    int formatCommandName(string &name);
    Command* addCommand(const string &name, const int& prefix, Command* command = new baseCommand(), istream &in = cin);
public:
    textCommands();
    //void loadCommands (const string &filename);
    //void saveCommands (const string &filename);
    Command* getCommand (string &name);//returns a Command object given the name of the command
    //Command* getSpecialAction (string &name);
    Command* createSequence (const string &filename, Command *command);
    //void addCommand (string name, Command *command);
};

#endif //TEXTCOMMANDS_H
