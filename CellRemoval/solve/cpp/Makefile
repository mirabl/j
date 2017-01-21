include ../Makefile.common

OUTPUT_D =../../build/cpp
SOLVER = $(OUTPUT_D)/CellRemovalSolver
COMPILER = g++ -std=gnu++0x -I$(GETTC_HOME)/include/cpp

$(SOLVER): CellRemovalSolver.cpp CellRemoval.cpp
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)
