//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_OCOMMAND_H
#define COMMAND_OCOMMAND_H

#include "commandDecorator.h"

class OCommand : public commandDecorator {
public:
	OCommand(Command * command);
    void execute(Game & game) override;
};

#endif //COMMAND_OCOMMAND_H
