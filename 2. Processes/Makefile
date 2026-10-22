cc=gcc

.PHONY: all
all: elephants example_fork interpreter_menu

elephants: elephants.c
	$(cc) elephants.c -o elephants

example_fork: example_fork.c
	$(cc) example_fork.c -o example_fork

interpreter_menu: interpreter_menu.c
	$(cc) interpreter_menu.c -o interpreter_menu

.PHONY: clean
clean:
	rm -rf elephants example_fork interpreter_menu
