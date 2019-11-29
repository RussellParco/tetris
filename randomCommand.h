//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_RANDOMCOMMAND_H
#define COMMAND_RANDOMCOMMAND_H

#include "commandDecorator.h"

class randomCommand : public commandDecorator {
public:
	randomCommand(Command * command);
    void execute(Game & game) override;
};

#endif //COMMAND_RANDOMCOMMAND_H
