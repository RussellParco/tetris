//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_LEVELUPCOMMAND_H
#define COMMAND_LEVELUPCOMMAND_H

#include "commandDecorator.h"

class levelupCommand : public commandDecorator {
public:
	levelupCommand(Command * command);
    void execute() override;
};

#endif //COMMAND_LEVELUPCOMMAND_H
