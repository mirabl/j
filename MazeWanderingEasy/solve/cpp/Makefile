include ../Makefile.common

OUTPUT_D =../../build/cpp
SOLVER = $(OUTPUT_D)/MazeWanderingEasySolver
COMPILER = g++ -std=gnu++0x -I$(GETTC_HOME)/include/cpp

$(SOLVER): MazeWanderingEasySolver.cpp MazeWanderingEasy.cpp
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)
