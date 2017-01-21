include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/ArcadeManaoSolver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): ArcadeManaoSolver.hs ArcadeManao.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

