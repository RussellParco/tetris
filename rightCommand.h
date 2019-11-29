//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_RIGHTCOMMAND_H
#define COMMAND_RIGHTCOMMAND_H

#include "commandDecorator.h"

class rightCommand : public commandDecorator {
public:
    rightCommand(Command * command);
    void execute(Game & game) override;
};

#endif //COMMAND_RIGHTCOMMAND_H
