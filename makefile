
default: mine-sweeper-program
	./mine-sweeper-program

mine-sweeper-program: *.c *.h
	gcc *.c -o mine-sweeper-program

.PHONY: default