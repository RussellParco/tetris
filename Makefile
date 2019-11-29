CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD

EXEC = play
OBJECTS = Command.o ICommand.o JCommand.o LCommand.o OCommand.o SCommand.o TCommand.o ZCommand.o baseCommand.o block.o board.o cell.o clockwiseCommand.o commandDecorator.o counterclockCommand.o display.o downCommand.o dropCommand.o iblock.o jblock.o lblock.o leftCommand.o level.o level0.o leveldownCommand.o levelupCommand.o  oblock.o playerdisplay.o restartCommand.o rightCommand.o sblock.o tblock.o game.o textCommands.o textdisplay.o zblock.o main.o norandomCommand.o randomCommand.o sequenceCommand.o level1.o level2.o level3.o level4.o 

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
