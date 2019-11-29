#include "dropCommand.h"
dropCommand::dropCommand(Command *command): commandDecorator{command} {}


void dropCommand::execute() {
    command->execute();
    game->drop();
}
