#include "randomCommand.h"
randomCommand::randomCommand(Command *command): commandDecorator{command} {}


void randomCommand::execute() {
    command->execute();
    game->random();
}
