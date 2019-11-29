#include "baseCommand.h"

baseCommand::baseCommand(Game *game){
	this->game = game;
}

baseCommand::~baseCommand(){}

void baseCommand::execute() {}
