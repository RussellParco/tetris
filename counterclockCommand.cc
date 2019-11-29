#include "counterclockCommand.h"
counterclockCommand::counterclockCommand(Command *command): commandDecorator{command} {}


void counterclockCommand::execute(Game & game) {
    command->execute(game);
    game.counterclockwise();
}
