include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/ArcadeManaoSolver

$(SOLVER): ArcadeManaoSolver.go ArcadeManao/ArcadeManao.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) ArcadeManaoSolver.go 

main: setup $(SOLVER)
