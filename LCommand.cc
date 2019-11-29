#include "LCommand.h"
LCommand::LCommand(Command *command): commandDecorator{command} {}


void LCommand::execute() {
    command->execute();
    game->L();
}
