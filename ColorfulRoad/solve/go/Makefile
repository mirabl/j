include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/ColorfulRoadSolver

$(SOLVER): ColorfulRoadSolver.go ColorfulRoad/ColorfulRoad.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) ColorfulRoadSolver.go 

main: setup $(SOLVER)
