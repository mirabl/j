include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/CellRemovalSolver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): CellRemovalSolver.hs CellRemoval.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

