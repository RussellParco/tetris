#ifndef COMMAND_CLOCKWISECOMMAND_H
#define COMMAND_CLOCKWISECOMMAND_H

#include "commandDecorator.h"

class clockwiseCommand : public commandDecorator {
public:
	clockwiseCommand(Command * command);
    void execute(Game &game) override;
};

#endif //COMMAND_CLOCKWISECOMMAND_H
