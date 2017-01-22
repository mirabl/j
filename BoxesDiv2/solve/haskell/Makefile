include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/BoxesDiv2Solver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): BoxesDiv2Solver.hs BoxesDiv2.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

