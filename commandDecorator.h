//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_COMMANDDECORATOR_H
#define COMMAND_COMMANDDECORATOR_H

#include "Command.h"

class commandDecorator: public Command{
Command command;
private:
    virtual void execute() = 0;
};

#endif //COMMAND_COMMANDDECORATOR_H
