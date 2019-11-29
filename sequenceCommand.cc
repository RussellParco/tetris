#include "sequenceCommand.h"
sequenceCommand::sequenceCommand(Command *command): commandDecorator{command} {}


void sequenceCommand::execute(Game &game) {
    command->execute(game);
    game.sequence(file);
}
