#include "JCommand.h"
JCommand::JCommand(Command *command): commandDecorator{command} {}


void JCommand::execute() {
    command->execute();
    game->J();
}
