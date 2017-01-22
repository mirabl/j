include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/ColorfulCoinsEasySolver

$(SOLVER): ColorfulCoinsEasySolver.go ColorfulCoinsEasy/ColorfulCoinsEasy.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) ColorfulCoinsEasySolver.go 

main: setup $(SOLVER)
