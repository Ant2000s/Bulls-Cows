all: bin/main
bin/main: build/main.o build/core.o
	gcc -Wall -Werror build/main.o build/core.o -o bin/main -lm

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/core.o: src/core.c
	gcc -Wall -Werror -c src/core.c -o build/core.o -lm
