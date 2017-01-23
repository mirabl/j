include ../Makefile.common

OUTPUT_D =../../build/cpp
SOLVER = $(OUTPUT_D)/PillarsDivTwoSolver
COMPILER = g++ -std=gnu++0x -I$(GETTC_HOME)/include/cpp

$(SOLVER): PillarsDivTwoSolver.cpp PillarsDivTwo.cpp
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)
