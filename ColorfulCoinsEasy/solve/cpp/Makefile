include ../Makefile.common

OUTPUT_D =../../build/cpp
SOLVER = $(OUTPUT_D)/ColorfulCoinsEasySolver
COMPILER = g++ -std=gnu++0x -I$(GETTC_HOME)/include/cpp

$(SOLVER): ColorfulCoinsEasySolver.cpp ColorfulCoinsEasy.cpp
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)
