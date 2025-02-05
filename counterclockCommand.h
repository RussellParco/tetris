#ifndef COMMAND_COUNTERCLOCKCOMMAND_H
#define COMMAND_COUNTERCLOCKCOMMAND_H

#include "commandDecorator.h"

class counterclockCommand : public commandDecorator {
public:
	counterclockCommand(Command *command);
    void execute(Game & game) override;
};

#endif //COMMAND_COUNTERCLOCKCOMMAND_H
