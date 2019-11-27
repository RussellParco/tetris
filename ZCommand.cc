#include "ZCommand.h"

void ZCommand::execute() {
    command->execute();
    game->Z();
}