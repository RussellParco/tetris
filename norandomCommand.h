#ifndef COMMAND_NORANDOMCOMMAND_H
#define COMMAND_NORANDOMCOMMAND_H

#include "commandDecorator.h"

class norandomCommand : public commandDecorator {
    std::string filename;
public:
	explicit norandomCommand(Command * command, istream &in = cin);
	explicit norandomCommand(Command * command, const string &name);
    void execute(Game &game) override;
};

#endif //COMMAND_NORANDOMCOMMAND_H
