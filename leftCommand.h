//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_LEFTCOMMAND_H
#define COMMAND_LEFTCOMMAND_H

#include "commandDecorator.h"

class leftCommand : public commandDecorator {
public:
    leftCommand(Command *command);
    void execute() override;
};

#endif //COMMAND_LEFTCOMMAND_H
