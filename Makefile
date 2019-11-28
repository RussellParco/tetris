CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = Game
OBJECTS = Command ICommand JCommand LCommand OCommand SCommand ZCommand TCommand baseCommand basiceffect blindeffect block board cell clockwiseCommand counterclockCommand commandDecorator coord display downCommand dropCommand effect effectdecorator forceeffect game graphicsdisplay heavyeffect iblock jblock lblock oblock sblock zblock tblock leftCommand level level0 level1 level2 level3 level4 leveldownCommand levelupCommand main norandomCommand randomCommand restartCommand rightCommand sequenceCommand textCommand textdisplay  




DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
