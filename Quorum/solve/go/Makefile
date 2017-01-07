include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/QuorumSolver

$(SOLVER): QuorumSolver.go Quorum/Quorum.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) QuorumSolver.go 

main: setup $(SOLVER)
