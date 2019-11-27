#include "leftCommand.h"

void leftCommand::execute() {
    command->execute();
    game->left();
}