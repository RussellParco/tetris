#include "TCommand.h"
TCommand::TCommand(Command *command): commandDecorator{command} {}


void TCommand::execute(Game &game) {
    command->execute(game);
    game.T();
}
