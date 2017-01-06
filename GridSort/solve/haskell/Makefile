include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/GridSortSolver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): GridSortSolver.hs GridSort.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

