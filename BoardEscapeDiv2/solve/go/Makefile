include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/BoardEscapeDiv2Solver

$(SOLVER): BoardEscapeDiv2Solver.go BoardEscapeDiv2/BoardEscapeDiv2.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) BoardEscapeDiv2Solver.go 

main: setup $(SOLVER)
