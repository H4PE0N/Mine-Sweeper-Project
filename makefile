
default: mine-sweeper-program
	./mine-sweeper-program

mine-sweeper-program: mine-sweeper-program.c
	gcc mine-sweeper-program.c -o mine-sweeper-program

.PHONY: default