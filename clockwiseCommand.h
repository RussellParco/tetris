//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_CLOCKWISECOMMAND_H
#define COMMAND_CLOCKWISECOMMAND_H

class clockwiseCommand : public commandDecorator {
public:
    void execute() override;
};

#endif //COMMAND_CLOCKWISECOMMAND_H
