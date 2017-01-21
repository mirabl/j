include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/MazeWanderingEasySolver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): MazeWanderingEasySolver.hs MazeWanderingEasy.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

