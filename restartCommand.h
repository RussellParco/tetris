//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_RESTARTCOMMAND_H
#define COMMAND_RESTARTCOMMAND_H

class restartCommand : public commandDecorator {
public:
    void execute() override;
};

#endif //COMMAND_RESTARTCOMMAND_H
