#include "leftCommand.h"

leftCommand::leftCommand(Command *command): commandDecorator{command} {}

void leftCommand::execute(Game & game){
    command->execute(game);
    game.left();

}
