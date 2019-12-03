#ifndef COMMAND_DROPCOMMAND_H
#define COMMAND_DROPCOMMAND_H

#include "commandDecorator.h"

class dropCommand : public commandDecorator {
public:
	dropCommand(Command * command);

    void execute(Game & game) override;
};

#endif //COMMAND_DROPCOMMAND_H
