include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/CellRemovalSolver

$(SOLVER): CellRemovalSolver.go CellRemoval/CellRemoval.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) CellRemovalSolver.go 

main: setup $(SOLVER)
