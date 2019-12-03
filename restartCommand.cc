#include "restartCommand.h"

restartCommand::restartCommand(Command *command): commandDecorator{command} {}

void restartCommand::execute(Game &game) {
    command->execute(game);
    game.restart();
}
