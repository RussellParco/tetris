#include "rightCommand.h"
rightCommand::rightCommand(Command *command): commandDecorator{command} {}


void rightCommand::execute(Game &game) {
    command->execute(game);
    game.right();
}
