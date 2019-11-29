#include "counterclockCommand.h"
counterclockCommand::counterclockCommand(Command *command): commandDecorator{command} {}


void counterclockCommand::execute() {
    command->execute();
    game->counterclockwise();
}
