//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_ZCOMMAND_H
#define COMMAND_ZCOMMAND_H

#include "commandDecorator.h"

class ZCommand : public commandDecorator {
public:
	ZCommand(Command * command);
    void execute(Game & game) override;
};

#endif //COMMAND_ZCOMMAND_H
