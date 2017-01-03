CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = Watan
OBJECTS = main.o cell.o dice.o fairdice.o grid.o loadeddice.o window.o student.o subject.o tiles.o
DEPENDS = ${OBJECTS:.o=.d}
GRAPHIC = -lX11
${EXEC}: ${OBJECTS}
	${CXX}  ${CXXFLAGS} ${OBJECTS} -o ${EXEC} ${GRAPHIC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
