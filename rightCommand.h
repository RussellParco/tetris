//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_RIGHTCOMMAND_H
#define COMMAND_RIGHTCOMMAND_H

class rightCommand : public commandDecorator {
public:
    void execute() override;
};

#endif //COMMAND_RIGHTCOMMAND_H
