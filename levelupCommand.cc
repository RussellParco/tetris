#include "levelupCommand.h"

void levelupCommand::execute() {
    command->execute();
    game->levelup();
}