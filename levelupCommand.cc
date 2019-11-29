#include "levelupCommand.h"
levelupCommand::levelupCommand(Command *command): commandDecorator{command} {}


void levelupCommand::execute(Game & game) {
    command->execute(game);
    game.levelup();
}
