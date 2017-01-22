include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/ColorfulCoinsEasySolver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): ColorfulCoinsEasySolver.hs ColorfulCoinsEasy.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

