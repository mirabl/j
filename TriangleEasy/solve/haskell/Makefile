include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/TriangleEasySolver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): TriangleEasySolver.hs TriangleEasy.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

