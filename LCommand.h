#ifndef COMMAND_LCOMMAND_H
#define COMMAND_LCOMMAND_H

#include "commandDecorator.h"

class LCommand : public commandDecorator {
public:
	LCommand(Command * command);
    void execute(Game & game ) override;
};

#endif //COMMAND_LCOMMAND_H
