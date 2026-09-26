hello: hello.o
	gcc hello.o -o hello

hello.o: hello.c
	gcc hello.c -c

.PHONY: clean
clean:
	rm -rf hello hello.o
