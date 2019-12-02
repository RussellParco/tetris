#include "sequenceCommand.h"
sequenceCommand::sequenceCommand(Command *command): commandDecorator{command} {
    std::cin >> filename;
}

sequenceCommand::sequenceCommand(Command *command, const string &name): commandDecorator{command}, filename{name}{}

void sequenceCommand::execute(Game &game) {
    command->execute(game);
    game.sequence(filename);
}
