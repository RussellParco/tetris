#include "rightCommand.h"
rightCommand::rightCommand(Command *command): commandDecorator{command} {}


void rightCommand::execute() {
    command->execute();
    game->right();
}
