include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/BoxesDiv2Solver

$(SOLVER): BoxesDiv2Solver.go BoxesDiv2/BoxesDiv2.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) BoxesDiv2Solver.go 

main: setup $(SOLVER)
