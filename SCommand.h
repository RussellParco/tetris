//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_SCOMMAND_H
#define COMMAND_SCOMMAND_H

#include "commandDecorator.h"

class SCommand : public commandDecorator {
public:
	SCommand(Command * command);
    void execute(Game & game) override;
};

#endif //COMMAND_SCOMMAND_H
