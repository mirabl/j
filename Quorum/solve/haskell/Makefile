include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/QuorumSolver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): QuorumSolver.hs Quorum.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

