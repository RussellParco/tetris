#include "JCommand.h"
JCommand::JCommand(Command *command): commandDecorator{command} {}


void JCommand::execute(Game & game) {
    command.execute(game);
    game.J(game);
}
