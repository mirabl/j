include ../Makefile.common

OUTPUT_D =../../build/cpp
SOLVER = $(OUTPUT_D)/ColorfulRoadSolver
COMPILER = g++ -std=gnu++0x -I$(GETTC_HOME)/include/cpp

$(SOLVER): ColorfulRoadSolver.cpp ColorfulRoad.cpp
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)
