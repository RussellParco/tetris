//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_COMMANDDECORATOR_H
#define COMMAND_COMMANDDECORATOR_H

#include "Command.h"

class commandDecorator: public Command{
<<<<<<< HEAD
public:
Command *command;
    ~commandDecorator() override{};
=======
protected:
    Command *command;
public:
    ~commandDecorator() override;
>>>>>>> a5f7528b576d23f0e73d3307dba7c0dcab750501
};

#endif //COMMAND_COMMANDDECORATOR_H
