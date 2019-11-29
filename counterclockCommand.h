//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_COUNTERCLOCKCOMMAND_H
#define COMMAND_COUNTERCLOCKCOMMAND_H

#include "commandDecorator.h"

class counterclockCommand : public commandDecorator {
public:
	counterclockCommand(Command *command);
    void execute() override;
};

#endif //COMMAND_COUNTERCLOCKCOMMAND_H
