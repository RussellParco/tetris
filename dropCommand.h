//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_DROPCOMMAND_H
#define COMMAND_DROPCOMMAND_H

class dropCommand : public commandDecorator {
public:
    void execute() override;
};

#endif //COMMAND_DROPCOMMAND_H
