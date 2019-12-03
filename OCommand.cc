#include "OCommand.h"

OCommand::OCommand(Command *command): commandDecorator{command} {}

void OCommand::execute(Game &game) {
    command->execute(game);
    game.O();
}
