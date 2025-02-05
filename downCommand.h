#ifndef COMMAND_DOWNCOMMAND_H
#define COMMAND_DOWNCOMMAND_H

#include "commandDecorator.h"

class downCommand : public commandDecorator {
public:
	downCommand(Command *command);
    void execute(Game & game) override;
};

#endif //COMMAND_DOWNCOMMAND_H
