include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/RollingDiceDivTwoSolver

$(SOLVER): RollingDiceDivTwoSolver.go RollingDiceDivTwo/RollingDiceDivTwo.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) RollingDiceDivTwoSolver.go 

main: setup $(SOLVER)
