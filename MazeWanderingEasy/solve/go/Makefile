include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/MazeWanderingEasySolver

$(SOLVER): MazeWanderingEasySolver.go MazeWanderingEasy/MazeWanderingEasy.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) MazeWanderingEasySolver.go 

main: setup $(SOLVER)
