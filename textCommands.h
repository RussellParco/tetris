//
// Created by Leo on 11/25/2019.
//

#ifndef TEXTCOMMANDS_H
#define TEXTCOMMANDS_H

//#include <fstream>
#include "Command.h"
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




using namespace std;

class textCommands {
    vector<string> names;
    vector<Command*> commands;
public:
    textCommands();
    //void loadCommands (const string &filename);
    //void saveCommands (const string &filename);
    Command* getCommand (const string &name);
    //void addCommand (string name, Command *command);
};

#endif //TEXTCOMMANDS_H
