#ifndef COMMAND_LEVELUPCOMMAND_H
#define COMMAND_LEVELUPCOMMAND_H

#include "commandDecorator.h"

class levelupCommand : public commandDecorator {
public:
	levelupCommand(Command * command);
    void execute(Game & game) override;
};

#endif //COMMAND_LEVELUPCOMMAND_H
