include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/PathGameDiv2Solver

$(SOLVER): PathGameDiv2Solver.go PathGameDiv2/PathGameDiv2.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) PathGameDiv2Solver.go 

main: setup $(SOLVER)
