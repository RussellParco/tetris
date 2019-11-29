#include "randomCommand.h"
randomCommand::randomCommand(Command *command): commandDecorator{command} {}


void randomCommand::execute(Game &game) {
    command->execute(game);
    game.random();
}
