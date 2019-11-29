//
// Created by Leo on 11/25/2019.
//

#ifndef COMMAND_COMMAND_H
#define COMMAND_COMMAND_H

class Game;
class Command {
    Game *game;
public:
    Command(Game* game):game(game){};
    virtual ~Command(){};
    virtual void execute() = 0;
};

#endif //COMMAND_COMMAND_H
