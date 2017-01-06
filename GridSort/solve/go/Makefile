include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/GridSortSolver

$(SOLVER): GridSortSolver.go GridSort/GridSort.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) GridSortSolver.go 

main: setup $(SOLVER)
