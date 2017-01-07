include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/OrderOfOperationsDiv2Solver

$(SOLVER): OrderOfOperationsDiv2Solver.go OrderOfOperationsDiv2/OrderOfOperationsDiv2.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) OrderOfOperationsDiv2Solver.go 

main: setup $(SOLVER)
