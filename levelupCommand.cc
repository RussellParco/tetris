#include "levelupCommand.h"
levelupCommand::levelupCommand(Command *command): commandDecorator{command} {}


void levelupCommand::execute() {
    command->execute();
    game->levelup();
}
