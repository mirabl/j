include ../Makefile.common

OUTPUT_D = ../../build/haskell
SOLVER = $(OUTPUT_D)/ThreeTeleportsSolver
COMPILER = ghc -i$(GETTC_HOME)/include/haskell -outputdir $(OUTPUT_D)

$(SOLVER): ThreeTeleportsSolver.hs ThreeTeleports.hs
	$(COMPILER) -o $(SOLVER) $<

main: setup $(SOLVER)

