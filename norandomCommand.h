//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_NORANDOMCOMMAND_H
#define COMMAND_NORANDOMCOMMAND_H

class norandomCommand : public commandDecorator {
    string file;
public:
    void execute() override;
};

#endif //COMMAND_NORANDOMCOMMAND_H
