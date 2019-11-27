#include "randomCommand.h"

void randomCommand::execute() {
    command->execute();
    game->random();
}