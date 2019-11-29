#include "dropCommand.h"
dropCommand::dropCommand(Command *command): commandDecorator{command} {}


void dropCommand::execute(Game & game) {
    command->execute(game);
    game.drop(game);
}
