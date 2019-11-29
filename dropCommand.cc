#include "dropCommand.h"
dropCommand::dropCommand(Command *command): commandDecorator{command} {}


void dropCommand::execute() {
    game->drop();
   void execute command->execute();
}
