#include "restartCommand.h"

void restartCommand::execute() {
    command->execute();
    game->restart();
}