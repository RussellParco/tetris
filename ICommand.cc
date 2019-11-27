#include "ICommand.h"

void ICommand::execute() {
    command->execute();
    game->I();
}