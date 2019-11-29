#include "SCommand.h"
SCommand::SCommand(Command *command): commandDecorator{command} {}


void SCommand::execute(Game &game) {
    command->execute(game);
    game.S();
}
