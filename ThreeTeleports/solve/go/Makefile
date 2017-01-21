include ../Makefile.common

OUTPUT_D =../../build/go
SOLVER = $(OUTPUT_D)/ThreeTeleportsSolver

$(SOLVER): ThreeTeleportsSolver.go ThreeTeleports/ThreeTeleports.go
	export GOPATH="$$GOPATH:$(GETTC_HOME)/include/go" \
		&& go build -o $(SOLVER) ThreeTeleportsSolver.go 

main: setup $(SOLVER)
