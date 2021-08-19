
default: mine-sweeper-program
	./mine-sweeper-program

mine-sweeper-program: mine-sweeper-program.c game-interface-program.c
	gcc mine-sweeper-program.c game-interface-program.c -o mine-sweeper-program

.PHONY: default