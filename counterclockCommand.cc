#include "counterclockCommand.h"

void counterclockCommand::execute() {
    command->execute();
    game->counterclockwise();
}
