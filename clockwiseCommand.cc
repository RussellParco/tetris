#include "clockwiseCommand.h"
clockwiseCommand::clockwiseCommand(Command *command): commandDecorator{command} {}


void clockwiseCommand::execute(Game &game) {
    command->execute(game);
    game.clockwise();
}
