include ../Makefile.common

OUTPUT_D =../../build/cpp
SOLVER = $(OUTPUT_D)/TriangleEasySolver
COMPILER = g++ -std=gnu++0x -I$(GETTC_HOME)/include/cpp

$(SOLVER): TriangleEasySolver.cpp TriangleEasy.cpp
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)
