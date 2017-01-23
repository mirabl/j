include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/DoubleWeightsSolver

$(SOLVER): DoubleWeightsSolver.go DoubleWeights/DoubleWeights.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) DoubleWeightsSolver.go 

main: setup $(SOLVER)
