#include "sequenceCommand.h"

void sequenceCommand::execute() {
    command->execute();
    game->sequence(file);
}