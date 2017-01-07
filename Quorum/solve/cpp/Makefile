include ../Makefile.common

OUTPUT_D =../../build/cpp
SOLVER = $(OUTPUT_D)/QuorumSolver
COMPILER = g++ -std=gnu++0x -I$(GETTC_HOME)/include/cpp

$(SOLVER): QuorumSolver.cpp Quorum.cpp
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)
