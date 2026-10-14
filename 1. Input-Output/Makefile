cc=gcc

.PHONY: all
all: example_stdout example_open rot13

example_stdout: example_stdout.c
	$(cc) example_stdout.c -o example_stdout

example_open: example_open.c
	$(cc) example_open.c -o example_open

rot13: rot13.c
	$(cc) rot13.c -o rot13

.PHONY: clean
clean:
	rm -rf example_stdout example_open rot13
