include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/TriangleEasySolver

$(SOLVER): TriangleEasySolver.go TriangleEasy/TriangleEasy.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) TriangleEasySolver.go 

main: setup $(SOLVER)
