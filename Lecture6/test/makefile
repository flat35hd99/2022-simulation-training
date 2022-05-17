CPP=g++
CPP_OPTIONS=-fopenmp -Wall -Wextra -O3

SRC=$(shell ls *.cpp)
EXEC=$(SRC:%.cpp=%.out)

ALL: $(EXEC)

%.out: %.cpp
	$(CPP) $(CPP_OPTIONS) $< -o $@
