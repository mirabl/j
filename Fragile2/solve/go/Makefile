include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/Fragile2Solver

$(SOLVER): Fragile2Solver.go Fragile2/Fragile2.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) Fragile2Solver.go 

main: setup $(SOLVER)
