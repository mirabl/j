include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/ConnectedComponentConstructionSolver

$(SOLVER): ConnectedComponentConstructionSolver.go ConnectedComponentConstruction/ConnectedComponentConstruction.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) ConnectedComponentConstructionSolver.go 

main: setup $(SOLVER)
