//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_JCOMMAND_H
#define COMMAND_JCOMMAND_H

class JCommand : public commandDecorator {
public:
    void execute() override;
};

#endif //COMMAND_JCOMMAND_H
