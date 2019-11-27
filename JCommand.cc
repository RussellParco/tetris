#include "JCommand.h"

void JCommand::execute() {
    command->execute();
    game->J();
}