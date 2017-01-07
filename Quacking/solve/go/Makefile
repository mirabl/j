include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/QuackingSolver

$(SOLVER): QuackingSolver.go Quacking/Quacking.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) QuackingSolver.go 

main: setup $(SOLVER)
