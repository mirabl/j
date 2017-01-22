include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/JumpFurtherSolver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): JumpFurtherSolver.hs JumpFurther.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

