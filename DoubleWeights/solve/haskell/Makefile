include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/DoubleWeightsSolver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): DoubleWeightsSolver.hs DoubleWeights.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

