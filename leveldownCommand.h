#ifndef COMMAND_LEVELDOWNCOMMAND_H
#define COMMAND_LEVELDOWNCOMMAND_H

#include "commandDecorator.h"

class leveldownCommand : public commandDecorator {
public:
	leveldownCommand(Command * command);
    void execute(Game & game) override;
};

#endif //COMMAND_LEVELDOWNCOMMAND_H
