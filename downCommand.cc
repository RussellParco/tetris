#include "downCommand.h"
downCommand::downCommand(Command *command): commandDecorator{command} {}


void downCommand::execute(Game & game) {
    command->execute(game);
    game.down();
}
