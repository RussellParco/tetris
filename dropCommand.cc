#include "dropCommand.h"

void dropCommand::execute() {
    command->execute();
    game->drop();
}