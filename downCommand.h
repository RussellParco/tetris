//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_DOWNCOMMAND_H
#define COMMAND_DOWNCOMMAND_H

class downCommand : public commandDecorator {
public:
    void execute() override;
};

#endif //COMMAND_DOWNCOMMAND_H
