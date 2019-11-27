#include "LCommand.h"

void LCommand::execute() {
    command->execute();
    game->L();
}