#include "SCommand.h"

void SCommand::execute() {
    command->execute();
    game->S();
}