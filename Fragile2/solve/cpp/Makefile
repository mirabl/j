include ../Makefile.common

OUTPUT_D =../../build/cpp
SOLVER = $(OUTPUT_D)/Fragile2Solver
COMPILER = g++ -std=gnu++0x -I$(GETTC_HOME)/include/cpp

$(SOLVER): Fragile2Solver.cpp Fragile2.cpp
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)
