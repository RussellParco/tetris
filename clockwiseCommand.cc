#include "clockwiseCommand.h"

void clockwiseCommand::execute() {
    command->execute();
    game->clockwise();
}