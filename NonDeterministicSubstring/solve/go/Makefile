include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/NonDeterministicSubstringSolver

$(SOLVER): NonDeterministicSubstringSolver.go NonDeterministicSubstring/NonDeterministicSubstring.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) NonDeterministicSubstringSolver.go 

main: setup $(SOLVER)
