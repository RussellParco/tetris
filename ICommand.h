//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_ICOMMAND_H
#define COMMAND_ICOMMAND_H

#include "commandDecorator.h"

class Game;

class ICommand : public commandDecorator {
public:
	ICommand(Command * command);
    void execute() override;
};

#endif //COMMAND_ICOMMAND_H
