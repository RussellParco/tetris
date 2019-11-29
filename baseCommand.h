//
// Created by Leo on 11/25/2019//

#ifndef COMMAND_BASECOMMAND_H
#define COMMAND_BASECOMMAND_H

#include "Command.h"

class baseCommand : public Command {
public:
    baseCommand(Game *game);
    ~baseCommand() override;
    void execute() override;
};

#endif //COMMAND_BASECOMMAND_H
