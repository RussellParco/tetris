//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_ICOMMAND_H
#define COMMAND_ICOMMAND_H

#include "commandDecorator.h"

class ICommand : public commandDecorator {
public:
    void execute() override;
};

#endif //COMMAND_ICOMMAND_H
