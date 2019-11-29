#include "norandomCommand.h"
norandomCommand::norandomCommand(Command *command): commandDecorator{command} {}


void norandomCommand::execute(Game &game) {
    command->execute(game);
    game.noRandom(file);
}
