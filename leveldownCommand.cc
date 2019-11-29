#include "leveldownCommand.h"
leveldownCommand::leveldownCommand(Command *command): commandDecorator{command} {}


void leveldownCommand::execute(Game & game) {
    command->execute(game);
    game.leveldown();
}
