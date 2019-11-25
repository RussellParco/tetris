//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_LEVELDOWNCOMMAND_H
#define COMMAND_LEVELDOWNCOMMAND_H

class leveldownCommand : public commandDecorator {
public:
    void execute() override;
};

#endif //COMMAND_LEVELDOWNCOMMAND_H
