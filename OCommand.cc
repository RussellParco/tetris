#include "OCommand.h"

void OCommand::execute() {
    command->execute();
    game->O();
}