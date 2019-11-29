#include "ICommand.h"
ICommand::ICommand(Command *command): commandDecorator{command} {}


void ICommand::execute(Game & game) {
    command->execute(game);
    game.I();
}
