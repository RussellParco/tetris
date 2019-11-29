//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_RANDOMCOMMAND_H
#define COMMAND_RANDOMCOMMAND_H

#include "commandDecorator.h"

class randomCommand : public commandDecorator {
public:
    void execute() override;
};

#endif //COMMAND_RANDOMCOMMAND_H
