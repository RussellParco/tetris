//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_CLOCKWISECOMMAND_H
#define COMMAND_CLOCKWISECOMMAND_H

#include "commandDecorator.h"

class clockwiseCommand : public commandDecorator {
public:
	clockwiseCommand(Command * command);
    void execute() override;
};

#endif //COMMAND_CLOCKWISECOMMAND_H
