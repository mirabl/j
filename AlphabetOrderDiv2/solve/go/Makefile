include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/AlphabetOrderDiv2Solver

$(SOLVER): AlphabetOrderDiv2Solver.go AlphabetOrderDiv2/AlphabetOrderDiv2.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) AlphabetOrderDiv2Solver.go 

main: setup $(SOLVER)
