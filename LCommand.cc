#include "LCommand.h"

LCommand::LCommand(Command *command): commandDecorator{command} {}

void LCommand::execute(Game & game) {
    command->execute(game);
    game.L();
}
