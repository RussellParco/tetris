#include "norandomCommand.h"
norandomCommand::norandomCommand(Command *command): commandDecorator{command} {}


void norandomCommand::execute() {
    command->execute();
    game->noRandom(file);
}
