#include "TCommand.h"
TCommand::TCommand(Command *command): commandDecorator{command} {}


void TCommand::execute() {
    command->execute();
    game->T();
}
