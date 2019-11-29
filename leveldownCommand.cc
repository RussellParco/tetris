#include "leveldownCommand.h"
leveldownCommand::leveldownCommand(Command *command): commandDecorator{command} {}


void leveldownCommand::execute() {
    command->execute();
    game->leveldown();
}
