//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_DOWNCOMMAND_H
#define COMMAND_DOWNCOMMAND_H

#include "commandDecorator.h"

class downCommand : public commandDecorator {
public:
	downCommand(Command *command);
    void execute() override;
};

#endif //COMMAND_DOWNCOMMAND_H
