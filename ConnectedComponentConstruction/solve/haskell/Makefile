include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/ConnectedComponentConstructionSolver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): ConnectedComponentConstructionSolver.hs ConnectedComponentConstruction.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

