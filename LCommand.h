//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_LCOMMAND_H
#define COMMAND_LCOMMAND_H

class LCommand : public commandDecorator {
public:
    void execute() override;
};

#endif //COMMAND_LCOMMAND_H
