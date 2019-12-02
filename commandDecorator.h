//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_COMMANDDECORATOR_H
#define COMMAND_COMMANDDECORATOR_H

#include "Command.h"
class Game;

class commandDecorator: public Command{
protected:
    Command *command;
public:
    commandDecorator(Command * command);
    virtual ~commandDecorator();

};

#endif //COMMAND_COMMANDDECORATOR_H
