//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_LEFTCOMMAND_H
#define COMMAND_LEFTCOMMAND_H

#include "commandDecorator.h"

class leftCommand : public commandDecorator {
    int prefix;
public:
    leftCommand(Command *command, int prefix);
    void execute(Game & game) override;
};

#endif //COMMAND_LEFTCOMMAND_H
