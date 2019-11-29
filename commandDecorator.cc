#include "commandDecorator.h"

~commandDecorator::commandDecorator() {
    delete command;
}
