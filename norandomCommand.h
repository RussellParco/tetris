//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_NORANDOMCOMMAND_H
#define COMMAND_NORANDOMCOMMAND_H

#include "commandDecorator.h"

class norandomCommand : public commandDecorator {
    std::string file;
public:
    void execute() override;
};

#endif //COMMAND_NORANDOMCOMMAND_H
