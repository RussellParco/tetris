//
// Created by Leo on 11/25/2019.
//

#ifndef TEXTCOMMANDS_H
#define TEXTCOMMANDS_H

#include "Command.h"

class textCommands {
    vector<string> names;
    vector<Command> commands;
public:
    loadCommands (const string &filename);
    saveCommands (const string &filename);
    getCommand (const string &name);
};

#endif //TEXTCOMMANDS_H
