CXX=g++
CXXFLAGS=-std=c++14 -MMD -g -Werror=vla #-Wall
OBJECTS=main.o elf.o character.o floor.o textdisplay.o cell.o observer.o subject.o state.o info.o stats.o character.o player.o shade.o human.o dwarf.o elf.o orc.o merchant.o halfling.o item.o potion.o restoreHP.o poisonHP.o boostAtk.o woundAtk.o boostDef.o woundDef.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=main

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o cc3k

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean
