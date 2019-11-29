#include "OCommand.h"
OCommand::OCommand(Command *command): commandDecorator{command} {}


void OCommand::execute() {
    command->execute();
    game->O();
}
