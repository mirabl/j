include ../Makefile.common

OUTPUT_D =../../build/cpp
SOLVER = $(OUTPUT_D)/GridSortSolver
COMPILER = g++ -std=gnu++0x -I$(GETTC_HOME)/include/cpp

$(SOLVER): GridSortSolver.cpp GridSort.cpp
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)
