#include "ICommand.h"
ICommand::ICommand(Command *command): commandDecorator{command} {}


void ICommand::execute() {
    command->execute();
    game->I();
}
