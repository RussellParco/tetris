//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_TCOMMAND_H
#define COMMAND_TCOMMAND_H

class TCommand : public commandDecorator {
public:
    void execute() override;
};

#endif //COMMAND_TCOMMAND_H
