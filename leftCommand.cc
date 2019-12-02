#include "leftCommand.h"

leftCommand::leftCommand(Command *command, int prefix): commandDecorator{command}, prefix{prefix} {}

void leftCommand::execute(Game & game){
    command->execute(game);
    game.left(prefix);

}
