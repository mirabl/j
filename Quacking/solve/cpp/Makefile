include ../Makefile.common

OUTPUT_D =../../build/cpp
SOLVER = $(OUTPUT_D)/QuackingSolver
COMPILER = g++ -std=gnu++0x -I$(GETTC_HOME)/include/cpp

$(SOLVER): QuackingSolver.cpp Quacking.cpp
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)
