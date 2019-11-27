//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_SEQUENCECOMMAND_H
#define COMMAND_SEQUENCECOMMAND_H

class sequenceCommand : public commandDecorator {
    string file;
public:
    void execute() override;
};

#endif //COMMAND_SEQUENCECOMMAND_H
