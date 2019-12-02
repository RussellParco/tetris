//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_SEQUENCECOMMAND_H
#define COMMAND_SEQUENCECOMMAND_H

#include "commandDecorator.h"

class sequenceCommand : public commandDecorator {
    std::string filename;
public:
	explicit sequenceCommand(Command * command, istream &in = cin);
	explicit sequenceCommand(Command * command, const string & name);
    void execute(Game &game) override;
};

#endif //COMMAND_SEQUENCECOMMAND_H
