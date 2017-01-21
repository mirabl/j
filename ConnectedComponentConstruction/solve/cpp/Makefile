include ../Makefile.common

OUTPUT_D =../../build/cpp
SOLVER = $(OUTPUT_D)/ConnectedComponentConstructionSolver
COMPILER = g++ -std=gnu++0x -I$(GETTC_HOME)/include/cpp

$(SOLVER): ConnectedComponentConstructionSolver.cpp ConnectedComponentConstruction.cpp
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)
