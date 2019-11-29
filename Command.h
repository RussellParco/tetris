//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_COMMAND_H
#define COMMAND_COMMAND_H

#include "game.h"
#include <string>


class Command {
public:

    virtual ~Command()= default;
    virtual void execute(Game &game) = 0;
};

#endif //COMMAND_COMMAND_H
