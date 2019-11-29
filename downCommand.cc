#include "downCommand.h"
downCommand::downCommand(Command *command): commandDecorator{command} {}


void downCommand::execute() {
    command->execute();
    game->down();
}
