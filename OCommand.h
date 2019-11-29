//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_OCOMMAND_H
#define COMMAND_OCOMMAND_H

#include "commandDecorator.h"

class OCommand : public commandDecorator {
public:
    void execute() override;
};

#endif //COMMAND_OCOMMAND_H
