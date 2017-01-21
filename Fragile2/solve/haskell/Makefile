include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/Fragile2Solver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): Fragile2Solver.hs Fragile2.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

