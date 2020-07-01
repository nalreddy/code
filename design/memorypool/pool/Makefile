CXX = g++
CXXFLAGS = -g -Wall
EXEC = test
OBJS = mempool.o test.o

${EXEC}: ${OBJS}
	${CXX} ${CXXFLAGS} -o ${EXEC} ${OBJS}

mempool.o: mempool.cpp mempool.hpp
	${CXX} ${CXXFLAGS}  -c mempool.cpp

test.o: test.cpp mempool.hpp
	${CXX} ${CXXFLAGS} -c test.cpp

clean:
	rm -rf ${EXEC} ${OBJS}
