include ../Makefile.common

OUTPUT_D =../../build/cpp
SOLVER = $(OUTPUT_D)/NonDeterministicSubstringSolver
COMPILER = g++ -std=gnu++0x -I$(GETTC_HOME)/include/cpp

$(SOLVER): NonDeterministicSubstringSolver.cpp NonDeterministicSubstring.cpp
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)
