include ../Makefile.common

OUTPUT_D =../../build/cpp
SOLVER = $(OUTPUT_D)/DoubleWeightsSolver
COMPILER = g++ -std=gnu++0x -I$(GETTC_HOME)/include/cpp

$(SOLVER): DoubleWeightsSolver.cpp DoubleWeights.cpp
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)
