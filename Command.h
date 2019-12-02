//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_COMMAND_H
#define COMMAND_COMMAND_H

#include "game.h"
#include <string>
#include <stdio.h>


class Command {
protected:
    //Game *game;
public:
    virtual ~Command(){};
    virtual void execute(Game &game) = 0;
};

#endif //COMMAND_COMMAND_H
