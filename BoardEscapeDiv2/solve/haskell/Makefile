include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/BoardEscapeDiv2Solver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): BoardEscapeDiv2Solver.hs BoardEscapeDiv2.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

