//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_LEVELDOWNCOMMAND_H
#define COMMAND_LEVELDOWNCOMMAND_H

#include "commandDecorator.h"

class leveldownCommand : public commandDecorator {
public:
	leveldownCommand(Command * command);
    void execute() override;
};

#endif //COMMAND_LEVELDOWNCOMMAND_H
