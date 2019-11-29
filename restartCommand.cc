#include "restartCommand.h"
restartCommand::restartCommand(Command *command): commandDecorator{command} {}


void restartCommand::execute() {
    command->execute();
    game->restart();
}
