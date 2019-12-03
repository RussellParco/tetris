#ifndef COMMAND_BASECOMMAND_H
#define COMMAND_BASECOMMAND_H

#include "Command.h"

class baseCommand : public Command {
public:
    void execute(Game &game) override;
};

#endif //COMMAND_BASECOMMAND_H
