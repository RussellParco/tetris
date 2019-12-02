#include "norandomCommand.h"
norandomCommand::norandomCommand(Command *command): commandDecorator{command} {
    std::cin >> filename;
}

norandomCommand::norandomCommand(Command *command, const string &name): commandDecorator{command}, filename{name}{}

void norandomCommand::execute(Game &game) {
    command->execute(game);
    game.noRandom(filename);
}
