#include "ZCommand.h"

ZCommand::ZCommand(Command *command): commandDecorator{command} {}

void ZCommand::execute(Game &game) {
    command->execute(game);
    game.Z();
}
