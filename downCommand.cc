#include "downCommand.h"

void downCommand::execute() {
    command->execute();
    game->down();
}