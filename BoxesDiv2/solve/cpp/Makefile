include ../Makefile.common

OUTPUT_D =../../build/cpp
SOLVER = $(OUTPUT_D)/BoxesDiv2Solver
COMPILER = g++ -std=gnu++0x -I$(GETTC_HOME)/include/cpp

$(SOLVER): BoxesDiv2Solver.cpp BoxesDiv2.cpp
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)
