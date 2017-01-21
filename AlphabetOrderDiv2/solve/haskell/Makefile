include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/AlphabetOrderDiv2Solver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): AlphabetOrderDiv2Solver.hs AlphabetOrderDiv2.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

