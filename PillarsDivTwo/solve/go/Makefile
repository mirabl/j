include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/PillarsDivTwoSolver

$(SOLVER): PillarsDivTwoSolver.go PillarsDivTwo/PillarsDivTwo.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) PillarsDivTwoSolver.go 

main: setup $(SOLVER)
