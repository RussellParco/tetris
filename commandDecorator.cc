#include "commandDecorator.h"

commandDecorator::commandDecorator(Command * command): command{command} {
	this->game = command->game;
}

commandDecorator::~commandDecorator() {
    delete command;
}
