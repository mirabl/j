include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/JumpFurtherSolver

$(SOLVER): JumpFurtherSolver.go JumpFurther/JumpFurther.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) JumpFurtherSolver.go 

main: setup $(SOLVER)
