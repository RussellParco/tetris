#include "ZCommand.h"
ZCommand::ZCommand(Command *command): commandDecorator{command} {}


void ZCommand::execute() {
    command->execute();
    game->Z();
}
