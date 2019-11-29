#include "leftCommand.h"

leftCommand::leftCommand(Command *command): commandDecorator{command} {}

void leftCommand::execute() {
    command->execute();
    game->left();
}
