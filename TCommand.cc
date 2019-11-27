#include "TCommand.h"

void TCommand::execute() {
    command->execute();
    game->T();
}