CXX=g++
CXXFLAGS=-std=c++14 -w -MMD -g -I include
SRC_DIR=src
OBJ_DIR=obj
SRC_FILES=$(wildcard ${SRC_DIR}/*.cc)
OBJECTS=$(patsubst ${SRC_DIR}/%.cc,${OBJ_DIR}/%.o,$(SRC_FILES))
DEPENDS=${OBJECTS:.o=.d}
EXEC=main

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o cc3k

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cc
	${CXX} ${CXXFLAGS} -c -o $@ $<

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean
