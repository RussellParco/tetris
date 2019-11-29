CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = play
OBJECTS = ICommand.o JCommand.o LCommand.o OCommand.o SCommand.o TCommand.o ZCommand.o baseCommand.o block.o board.o cell.o clockwiseCommand.o commandDecorator.o counterclockCommand.o display.o downCommand.o dropCommand.o game.o iblock.o jblock.o lblock.o leftCommand.o level.o level0.o leveldownCommand.o levelupCommand.o main.o norandomCommand.o oblock.o playerdisplay.o randomCommand.o restartCommand.o rightCommand.o sblock.o sequenceCommand.o tblock.o textCommand.o textdisplay.o zblock.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
