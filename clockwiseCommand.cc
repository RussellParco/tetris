#include "clockwiseCommand.h"
clockwiseCommand::clockwiseCommand(Command *command): commandDecorator{command} {}


void clockwiseCommand::execute() {
    command->execute();
    game->clockwise();
}
