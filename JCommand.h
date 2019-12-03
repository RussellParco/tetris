#ifndef COMMAND_JCOMMAND_H
#define COMMAND_JCOMMAND_H

#include "commandDecorator.h"

class JCommand : public commandDecorator {
public:
	JCommand(Command * command);
    void execute(Game & game) override;
};

#endif //COMMAND_JCOMMAND_H
