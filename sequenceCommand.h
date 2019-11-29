//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_SEQUENCECOMMAND_H
#define COMMAND_SEQUENCECOMMAND_H

#include "commandDecorator.h"
#include <string>

class sequenceCommand : public commandDecorator {
    std::string file;
public:
	sequenceCommand(Command * command);
    void execute(Game & game) override;
};

#endif //COMMAND_SEQUENCECOMMAND_H
