//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_LCOMMAND_H
#define COMMAND_LCOMMAND_H

#include "commandDecorator.h"

class LCommand : public commandDecorator {
public:
	LCommand(Command * command);
    void execute() override;
};

#endif //COMMAND_LCOMMAND_H
