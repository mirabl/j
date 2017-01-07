include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/QuackingSolver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): QuackingSolver.hs Quacking.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

