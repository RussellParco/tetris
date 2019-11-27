#include "leveldownCommand.h"

void leveldownCommand::execute() {
    command->execute();
    game->leveldown();
}