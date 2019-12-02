#include "rightCommand.h"
rightCommand::rightCommand(Command *command, int prefix): commandDecorator{command}, prefix{prefix} {}


void rightCommand::execute(Game &game) {
    command->execute(game);
    game.right(prefix);
}
