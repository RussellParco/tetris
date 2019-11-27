#include "norandomCommand.h"

void norandomCommand::execute() {
    command->execute();
    game->norandom(file);
}