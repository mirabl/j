include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/RollingDiceDivTwoSolver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): RollingDiceDivTwoSolver.hs RollingDiceDivTwo.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

