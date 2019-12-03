#ifndef COMMAND_RESTARTCOMMAND_H
#define COMMAND_RESTARTCOMMAND_H

#include "commandDecorator.h"

class restartCommand : public commandDecorator {
public:
	restartCommand(Command * command);
    void execute(Game & game) override;
};

#endif //COMMAND_RESTARTCOMMAND_H
