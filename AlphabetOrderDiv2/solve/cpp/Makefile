include ../Makefile.common

OUTPUT_D =../../build/cpp
SOLVER = $(OUTPUT_D)/AlphabetOrderDiv2Solver
COMPILER = g++ -std=gnu++0x -I$(GETTC_HOME)/include/cpp

$(SOLVER): AlphabetOrderDiv2Solver.cpp AlphabetOrderDiv2.cpp
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)
