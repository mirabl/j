include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/PillarsDivTwoSolver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): PillarsDivTwoSolver.hs PillarsDivTwo.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

