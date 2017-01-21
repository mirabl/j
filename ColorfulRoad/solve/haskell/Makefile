include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/ColorfulRoadSolver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): ColorfulRoadSolver.hs ColorfulRoad.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

