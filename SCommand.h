//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_SCOMMAND_H
#define COMMAND_SCOMMAND_H

#include "commandDecorator.h"

class SCommand : public commandDecorator {
public:
    void execute() override;
};

#endif //COMMAND_SCOMMAND_H
