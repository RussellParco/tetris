#include "rightCommand.h"

void rightCommand::execute() {
    command->execute();
    game->right();
}