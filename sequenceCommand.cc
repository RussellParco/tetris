#include "sequenceCommand.h"
sequenceCommand::sequenceCommand(Command *command): commandDecorator{command} {}


void sequenceCommand::execute() {
    command->execute();
    game->sequence(file);
}
