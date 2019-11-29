#include "SCommand.h"
SCommand::SCommand(Command *command): commandDecorator{command} {}


void SCommand::execute() {
    command->execute();
    game->S();
}
