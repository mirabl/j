include ../Makefile.common

OUTPUT_D =../../build/cpp
SOLVER = $(OUTPUT_D)/JumpFurtherSolver
COMPILER = g++ -std=gnu++0x -I$(GETTC_HOME)/include/cpp

$(SOLVER): JumpFurtherSolver.cpp JumpFurther.cpp
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)
