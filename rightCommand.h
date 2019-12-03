#ifndef COMMAND_RIGHTCOMMAND_H
#define COMMAND_RIGHTCOMMAND_H

#include "commandDecorator.h"

class rightCommand : public commandDecorator {
    int prefix;
public:
    rightCommand(Command * command, int prefix);
    void execute(Game & game) override;
};

#endif //COMMAND_RIGHTCOMMAND_H
