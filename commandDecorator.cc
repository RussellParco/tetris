#include "commandDecorator.h"

commandDecorator::commandDecorator(Command * command): command{command} {}

commandDecorator::~commandDecorator() {
    delete command;
}
